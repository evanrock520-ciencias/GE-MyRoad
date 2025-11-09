#include <iostream>
#include <string>
using namespace std;

class Matrix
{
private:
    int height;
    int lenght;
    int* dimensions;
    float** matrix;

public:
    Matrix(int h, int l) 
    {
        this->height = h;
        this->lenght = l;
        this->dimensions = new int[2];
        this->matrix = new float*[height];
        this->dimensions[0] = height;
        this->dimensions[1] = lenght;
    }

    string getDimensions()
    {
        return "(" + to_string(height) + "," + to_string(lenght) + ")";
    }

    void setValues()
    {
        for (int i = 0; i < height; i++)
        {
            float* row = new float[lenght];
            for (int j = 0; j < lenght; j++) 
            {
                row[j] = 1;
            }
            matrix[i] = row;
        }
    }

    string toString()
    {
        string result = "";
        for (int i = 0; i < height; i++)
        {
            result += "[";
            for (int j = 0; j < lenght; j++)
            {
                result += to_string(matrix[i][j]);
                if (j < lenght - 1)
                    result += ", ";
            }
            result += "]";
            if (i < height - 1)
                result += "\n";
        }
        return result;
    }

};

int main()
{
    Matrix matriz = Matrix(3,3);
    cout << matriz.getDimensions() << endl;
    matriz.setValues();
    cout << matriz.toString() << endl;
    return 0;
}