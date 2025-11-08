#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

float getSlope(Point p1, Point p2);
float getDistance(Point p1, Point p2);
void getChars(Point p1);

int main() 
{
    Point p1;
    Point p2;
    float slope;
    float distance;

    cout << "Insert a x coordinate" << endl;
    cin >> p1.x;
    cout << "Insert a y coordinate" << endl;
    cin >> p1.y;

    cout << "Insert a x coordinate" << endl;
    cin >> p2.x;
    cout << "Insert a y coordinate" << endl;
    cin >> p2.y;

    slope = getSlope(p1, p2);
    distance = getDistance(p1, p2);

    cout << "The slope is " << slope << endl;
    cout << "The distance between the points is of " << distance << endl;
    
    return 0;
}

float getSlope(Point p1, Point p2)
{
    int deltaX = p2.x - p1.x;
    int deltaY = p2.y - p1.y;

    if (deltaX == 0) {
        cout << "Slope is infinite (vertical line)." << endl;
        return INFINITY;
    }

    return static_cast<float>(deltaY) / deltaX;
}


float getDistance(Point p1, Point p2) 
{
    float distance;
    float deltaX;
    float deltaY;

    deltaX = p1.x - p2.x;
    deltaY = p1.y - p2.y;
    distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    return distance;
}

void getChars(Point p1)
{
    cout << "(" << p1.x << ", " << p1.y << ")";
}