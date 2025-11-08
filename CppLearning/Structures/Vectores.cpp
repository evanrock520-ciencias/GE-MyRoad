#include <iostream>
#include <cmath>
using namespace std;

struct Vector
{
    float x;
    float y;

    float length() const
    {
        return (sqrt((x*x) + (y*y)));
    }

    Vector normalize() const
    {
        float len = length();
        if (len == 0) return {0, 0};
        return { x / len, y / len };
    }

    Vector add(Vector vec) const
    {
        return {x + vec.x, y + vec.y};
    }

    float dot(Vector vec) const
    {
        return x*vec.x + y*vec.y;
    }

    string toString() const
    {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
};

int main()
{
    Vector v1 = {10, 5};
    Vector v2 = {2, 10};
    
    float dot = v1.dot(v2);
    Vector newVec = v1.add(v2);

    cout << "Dot product between " << v1.toString() << " and " << v2.toString() << " is " << dot << endl;
    cout << "The resultant vector between " << v1.toString() << " and " << v2.toString() << "is " << newVec.toString() << endl; 

    return 0;
}
