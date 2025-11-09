#include <iostream>
using namespace std;

class Rectangle
{
private: 
    float height;
    float length;

public:
    Rectangle(float h, float l)
    {
        this->height = h;
        this->length = l;
    }
    
    float area()
    {
        return this->height * this->length;
    }

    float perimeter() 
    {
        return (2 * this->height) + (2 * this->length);
    }
    
    float getHeight() 
    {
        return this->height;
    }

    float getLength() 
    {
        return this->length;
    }
};

int main()
{
    float height;
    float length;
    cout << "Insert a number for lenght" << endl;
    cin >> length;
    cout << "Insert a number for height" << endl;
    cin >> height;

    Rectangle rectangle = Rectangle(height, length);

    cout << "Height : " << rectangle.getHeight() << endl; 
    cout << "Length : " << rectangle.getLength() << endl;    
    cout << "Area : " << rectangle.area() << endl;
    cout << "Perimeter : " << rectangle.perimeter() << endl;

    return 0;
}
