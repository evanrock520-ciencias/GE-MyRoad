#include <iostream>
#include <string>

using namespace std;

bool isEven(int number);
void evenString(bool even);
int number;
bool even;

int main()
{
    cout << "Insert a number" << endl;
    cin >> number;
    even = isEven(number);
    evenString(even);
}

bool isEven(int number) 
{
    return number % 2 == 0;
}

void evenString(bool even)
{
    if (even)
    {
        cout << "Your number is even" << endl;
    }
    else 
    {
        cout << "Your number isn't even" << endl;
    }
}