#include <iostream>
using namespace std;

void increment(int& number);

int main() 
{
    int number = 8;
    cout << number << endl;
    int& ref = number; // This is the way we declarate a reference on C++
    // ref is actually an alias
    increment(number);
    cout << number << endl;
    cout << ref << endl;
}

void increment(int& number) 
{
    number++;
}