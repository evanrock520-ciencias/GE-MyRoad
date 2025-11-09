#include <iostream>
using namespace std;

bool isPrime(int number);

int main()
{
    int number;
    bool prime;
    cout << "Insert a number" << endl;
    cin >> number;
    prime = isPrime(number);
    cout << prime << endl;
    return 0;
}

bool isPrime(int number)
{
    int index = 2;
    while(index <= number / 2)
    {
        if (number % index == 0)
            return false;
        index++;
    }
    return true;
}

