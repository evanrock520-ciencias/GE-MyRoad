#include <iostream>
using namespace std;

int factorial(int number);

int main()
{
    int number;
    int factRes;
    cout << "Insert a number" << endl;
    cin >> number;
    factRes = factorial(number);
    cout << "The factorial of " << number << " is " << factRes << endl;
    return 0;
}

int factorial(int number)
{
    if(number < 2)
    {
        return 1;
    }
    return number * factorial(number - 1);
}

