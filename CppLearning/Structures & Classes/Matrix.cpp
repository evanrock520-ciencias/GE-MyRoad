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
        this->dimensions[0] = height;
        this->dimensions[1] = lenght;
        this->matrix = new float*[height];
        for (int i = 0; i < height; i++)
            this->matrix[i] = new float[lenght];
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
                row[j] = 2;
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

    Matrix add(const Matrix& m2)
    {
        Matrix sum(height, lenght);
        for (int i = 0; i < height; i++)
        {
            float* row = new float[lenght];
            for (int j = 0; j < lenght; j++)
            {
                row[j] = this->matrix[i][j] + m2.matrix[i][j];
            }
            sum.matrix[i] = row;
        }
        return sum;
    }

};

int main()
{
    Matrix m1 = Matrix(3,3);
    Matrix m2 = Matrix(3, 3);
    cout << m1.getDimensions() << endl;
    m1.setValues();
    m2.setValues();
    cout << m1.toString() << endl;
    Matrix mr = m1.add(m2);
    cout << "====================" << endl;
    cout << mr.toString() << endl;
    return 0;
}
