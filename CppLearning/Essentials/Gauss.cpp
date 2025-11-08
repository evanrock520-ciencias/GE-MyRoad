#include <iostream>

using namespace std;

int whileGauss(int number);
int realGauss(int number);

int main() 
{
    int number;
    int add;
    int sum;

    cout << "Insert a number" << endl;
    cin >> number;
    add = whileGauss(number);
    sum = realGauss(number);
    cout << "Gaussian Sum of " << number << " is " << add << endl;
    cout << "Gaussian Sum of " << number << " is " << sum << endl; 
}

int whileGauss(int number)
{
    int add = 0;
    while(number > 0) 
    {
        add += number;
        number -= 1;
    }
    return add;
}

int realGauss(int number)
{
    return (number * (number + 1)) / 2;
}