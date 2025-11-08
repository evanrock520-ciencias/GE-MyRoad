#include <iostream>

using namespace std;

float calculateArea(float base, float height);
float base;
float height;
float area;

int main()
{
    cout << "Insert your triangle base" << endl;
    cin >> base;
    cout << "Insert your triangle height" << endl;
    cin >> height;
    area = calculateArea(base, height);
    cout << "The area of that triagle is " << area << " m²" << endl;
    return 0;
}

float calculateArea(float base, float height)
{
    return (base * height) / 2;
}
