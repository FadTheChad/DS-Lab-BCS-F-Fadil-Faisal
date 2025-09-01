#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter rows: ";
    cin >> n;
    cout << "Enter cols: ";
    cin >> m;

    int** mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[m];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    cout << "\nMatrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // Compressed form is displaying a matrix without zeros?
    cout << "\nCompressed form (row col val):\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] != 0)
                cout << "(" << i << ", " << j << ", " << mat[i][j] << ")" << endl;

    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}