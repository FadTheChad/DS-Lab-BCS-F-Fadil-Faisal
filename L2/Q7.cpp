#include <iostream>

using namespace std;

int main()
{
    int d;
    cout << "Enter number of departments: ";
    cin >> d;

    int** salary = new int*[d];
    int* emp = new int[d];

    for (int i = 0; i < d; i++)
    {
        cout << "Enter employees in dept " << i + 1 << ": ";
        cin >> emp[i];

        salary[i] = new int[emp[i]];
        cout << "Enter salaries for dept " << i + 1 << ":\n";
        for (int j = 0; j < emp[i]; j++)
            cin >> salary[i][j];
    }

    cout << "\nHighest salary in each dept:\n";
    for (int i = 0; i < d; i++)
    {
        int mx = salary[i][0];
        for (int j = 1; j < emp[i]; j++)
            if (salary[i][j] > mx)
                mx = salary[i][j];
        cout << "Dept " << i + 1 << ": " << mx << endl;
    }

    int best = 0;
    double bestAvg = 0;
    for (int i = 0; i < d; i++)
    {
        double sum = 0;
        for (int j = 0; j < emp[i]; j++)
            sum += salary[i][j];
        double avg = sum / emp[i];
        if (i == 0 || avg > bestAvg)
        {
            bestAvg = avg;
            best = i;
        }
    }

    cout << "\nDept with highest avg salary: " << best + 1;
    cout << " (Avg = " << bestAvg << ")" << endl;

    for (int i = 0; i < d; i++)
        delete[] salary[i];
    delete[] salary;
    delete[] emp;

    return 0;
}