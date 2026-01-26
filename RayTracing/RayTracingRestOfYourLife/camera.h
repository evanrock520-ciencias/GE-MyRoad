#ifndef CAMERA_H
#define CAMERA_H

#include "interval.h"
#include "color.h"
#include "rtweekend.h"
#include "vec3.h"
#include "material.h"
#include <cmath>
#include <omp.h>
#include <vector>

class camera {
  public:
    double aspect_ratio      = 1.0;  
    int    image_width       = 100;  
    int    samples_per_pixel = 10;   
    int    max_depth         = 10;  
    color  background;

    double vfov = 90;
    point3 lookfrom = point3(0,0,-1);
    point3 lookat   = point3(0,0,0);
    vec3   vup      = vec3(0,1,0);

    double defocus_angle = 0;
    double focus_dist    = 10;
    
    void render(const hittable& world) {
        initialize();

        int image_height = static_cast<int>(image_width / aspect_ratio);
        if (image_height < 1) image_height = 1;

        std::vector<color> pixel_buffer(image_width * image_height);

        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        std::cerr << "Iniciando renderizado con " << omp_get_max_threads() << " hilos...\n";

        #pragma omp parallel for schedule(static)
        for (int j = 0; j < image_height; ++j) { 
        
            if (omp_get_thread_num() == 0) {
                std::cerr << "\rScanlines: " << j << '/' << image_height << std::flush;
            }

            for (int i = 0; i < image_width; ++i) {
                color pixel_color(0,0,0);
                
                for (int s_j = 0; s_j < sqrt_spp; s_j++) {
                    for (int s_i = 0; s_i < sqrt_spp; s_i++) {
                        ray r = get_ray(i, j, s_i, s_j); 
                        pixel_color += ray_color(r, max_depth, world);
                    }
                }

                int index = j * image_width + i;
                pixel_buffer[index] = pixel_color; 
            }
        }
        
        std::cerr << "\nRenderizado completo. Escribiendo salida (Serial)...\n";

        for (const auto& pixel_col : pixel_buffer) {
            write_color(std::cout, pixel_col, samples_per_pixel);
        }

        std::cerr << "\nDone.\n";
    }

    private:
        int    image_height;         // Rendered image height
        double pixel_samples_scale;  // Color scale factor for a sum of pixel samples
        int    sqrt_spp;             // Square root of number of samples per pixel
        double recip_sqrt_spp;       // 1 / sqrt_spp
        point3 center;               // Camera center
        point3 pixel00_loc;          // Location of pixel 0, 0
        vec3   pixel_delta_u;        // Offset to pixel to the right
        vec3   pixel_delta_v;        // Offset to pixel below
        vec3   u, v, w;              // Camera frame basis vectors
        vec3   defocus_disk_u;       // Defocus disk horizontal radius
        vec3   defocus_disk_v;       // Defocus disk vertical radius

        void initialize() {
            image_height = int(image_width / aspect_ratio);
            image_height = (image_height < 1) ? 1 : image_height;

            sqrt_spp = int(std::sqrt(samples_per_pixel));
            pixel_samples_scale = 1.0 / (sqrt_spp * sqrt_spp);
            recip_sqrt_spp = 1.0 / sqrt_spp;

            center = lookfrom;

            // Determine viewport dimensions.
            auto theta = degrees_to_radians(vfov);
            auto h = std::tan(theta/2);
            auto viewport_height = 2 * h * focus_dist;
            auto viewport_width = viewport_height * (double(image_width)/image_height);

            // Calculate the u,v,w unit basis vectors for the camera coordinate frame.
            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup, w));
            v = cross(w, u);

            // Calculate the vectors across the horizontal and down the vertical viewport edges.
            vec3 viewport_u = viewport_width * u;    // Vector across viewport horizontal edge
            vec3 viewport_v = viewport_height * -v;  // Vector down viewport vertical edge

            // Calculate the horizontal and vertical delta vectors from pixel to pixel.
            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v / image_height;

            // Calculate the location of the upper left pixel.
            auto viewport_upper_left = center - (focus_dist * w) - viewport_u/2 - viewport_v/2;
            pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

            auto defocus_radius = focus_dist * std::tan(degrees_to_radians(defocus_angle / 2));
            defocus_disk_u = u * defocus_radius;
            defocus_disk_v = v * defocus_radius;
        }

        color ray_color(const ray& r, int depth, const hittable& world) const {
            if (depth <= 0)
                return color(0,0,0);

            hit_record rec;

            if (!world.hit(r, interval(0.001, infinity), rec))
                return background;

            ray scattered;
            color attenuation;
            color color_from_emission = rec.mat->emitted(rec.u, rec.v, rec.p);

            if (!rec.mat->scatter(r, rec, attenuation, scattered))
                return color_from_emission;

            color color_from_scatter = attenuation * ray_color(scattered, depth-1, world);

            return color_from_emission + color_from_scatter;
        }

        ray get_ray(int i, int j, int s_i, int s_j) const {
            auto offset = sample_square_stratified(s_i, s_j);
            auto pixel_sample = pixel00_loc
                            + ((i + offset.x()) * pixel_delta_u)
                            + ((j + offset.y()) * pixel_delta_v);

            auto ray_origin = (defocus_angle <= 0) ? center : defocus_disk_sample();
            auto ray_direction = pixel_sample - ray_origin;
            auto ray_time = random_double();

            return ray(ray_origin, ray_direction, ray_time);
        }

        vec3 sample_square_stratified(int s_i, int s_j) const {
            auto px = ((s_i + random_double()) * recip_sqrt_spp) - 0.5;
            auto py = ((s_j + random_double()) * recip_sqrt_spp) - 0.5;

            return vec3(px, py, 0);
        }

        vec3 sample_square() const {
            // Returns the vector to a random point in the [-.5,-.5]-[+.5,+.5] unit square.
            return vec3(random_double() - 0.5, random_double() - 0.5, 0);
        }

        point3 defocus_disk_sample() const {
            // Returns a random point in the camera defocus disk.
            auto p = random_in_unit_disk();
            return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
        }
};

#endif