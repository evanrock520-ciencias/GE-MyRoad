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

    Matrix operator+(const Matrix& m2)
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

    Matrix operator-(const Matrix& m2)
    {
        Matrix substract(height, lenght);
        for (int i = 0; i < height; i++)
        {
            float* row = new float[lenght];
            for (int j = 0; j < lenght; j++)
            {
                row[j] = this->matrix[i][j] - m2.matrix[i][j];
            }
            substract.matrix[i] = row;
        }
        return substract;
    }

    Matrix scalarMultiplication(float scalar)
    {
        Matrix multiScalar(height, lenght);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < lenght; j++)
            {
                multiScalar.matrix[i][j] = this->matrix[i][j] * scalar;
            }
        }
        return multiScalar;
    }

    Matrix operator*(const Matrix& m2)
    {
        if (this->lenght != m2.lenght)
        {
            throw invalid_argument("The number of columns of the first matrix must equal the number of rows of the second matrix.");
        }

        Matrix result(this->height, m2.lenght);

        for (int i = 0; i < this->height; i++) 
        {
            for (int j = 0; j < m2.lenght; j++) 
            {
                float sum = 0.0f;
                for (int k = 0; k < this->lenght; k++) 
                {
                    sum += this->matrix[i][k] * m2.matrix[k][j];
                }
                result.matrix[i][j] = sum;
            }
        }
        return result;
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
    Matrix mr = m1 + m2;
    Matrix ms = m1 - m2;
    Matrix msp = m1.scalarMultiplication(12.0);
    Matrix mm = m1 * msp;
    cout << "====================" << endl;
    cout << mr.toString() << endl;
    cout << "====================" << endl;
    cout << ms.toString() << endl;
    cout << "====================" << endl;
    cout << msp.toString() << endl;
    cout << "====================" << endl;
    cout << mm.toString() << endl;

    return 0;
}
