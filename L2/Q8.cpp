#include <iostream>

using namespace std;

// Measured temp in double type for precision.
int main()
{
    int n, m;
    cout << "Enter n (days): ";
    cin >> n;
    cout << "Enter m (times per day): ";
    cin >> m;

    double** temp = new double*[n];

    for (int i = 0; i < n; i++)
        temp[i] = new double[m];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter temps for day " << i + 1 << ":\n";
        for (int j = 0; j < m; j++)
            cin >> temp[i][j];
    }

    double* avg = new double[n];

    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < m; j++)
            sum += temp[i][j];
        avg[i] = sum / m;
    }

    cout << "\nDaily avg temps:\n";
    for (int i = 0; i < n; i++)
        cout << "Day " << i + 1 << ": " << avg[i] << endl;

    int hot = 0, cold = 0;
    for (int i = 1; i < n; i++)
    {
        if (avg[i] > avg[hot]) hot = i;
        if (avg[i] < avg[cold]) cold = i;
    }

    cout << "\nHottest day: " << hot + 1 << " (Avg = " << avg[hot] << ")" << endl;
    cout << "Coldest day: " << cold + 1 << " (Avg = " << avg[cold] << ")" << endl;

    for (int i = 0; i < n; i++)
        delete[] temp[i];

    delete[] temp;
    delete[] avg;

    return 0;
}