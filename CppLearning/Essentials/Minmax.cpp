#include <iostream>
#include <string> 
#include <limits> 

using namespace std;

int max_value(int* numbers, int length);
int min_value(int* numbers, int length);

int main()
{
    int numbers[] = {94, 92, 76, 5, 12, 43, 36, 9, 18};
    
    int length = sizeof(numbers) / sizeof(numbers[0]);

    int maxValue = max_value(numbers, length);
    int minValue = min_value(numbers, length);

    cout << "Los numeros son: {94, 92, 76, 5, 12, 43, 36, 9, 18}" << endl; 
    cout << "El valor maximo es: " << maxValue << endl;
    cout << "El valor minimo es: " << minValue << endl;

    return 0;
}

int max_value(int* numbers, int length)
{
    int maxValue = numbers[0]; 
    for(int i = 1; i < length; i++)
    {
        if (maxValue < numbers[i])
            maxValue = numbers[i];
    }
    return maxValue;
}

int min_value(int* numbers, int length)
{
    int minValue = numbers[0]; 
    for(int i = 1; i < length; i++) 
    {
        if (minValue > numbers[i]) 
            minValue = numbers[i];
    }
    return minValue;
}
