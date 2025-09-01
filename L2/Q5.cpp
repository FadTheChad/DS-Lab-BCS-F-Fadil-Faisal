#include <iostream>
using namespace std;

class Matrix
{
    int rows, cols;
    int** data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) data[i] = new int[cols];
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    void input()
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator-(const Matrix& other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }
};

int main()
{
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Matrix m1(r, c), m2(r, c);

    cout << "Enter elements of first matrix:\n";
    m1.input();

    cout << "Enter elements of second matrix:\n";
    m2.input();

    cout << "Addition:\n";
    Matrix sum = m1 + m2;
    sum.display();

    cout << "Subtraction:\n";
    Matrix diff = m1 - m2;
    diff.display();

    return 0;
}