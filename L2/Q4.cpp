#include <iostream>
using namespace std;

class Expenses
{
    double* data;
    int size;

public:
    Expenses(int n)
    {
        size = n;
        data = new double[size];
    }

    ~Expenses()
    {
        delete[] data;
    }

    void setExpense(int i, double val)
    {
        if (i >= 0 && i < size) data[i] = val;
    }

    void resize(int newSize)
    {
        double* newData = new double[newSize];
        for (int i = 0; i < size && i < newSize; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
    }

    double total()
    {
        double sum = 0;
        for (int i = 0; i < size; i++) sum += data[i];
        return sum;
    }

    double average()
    {
        if (size == 0) return 0;
        return total() / size;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    int n;
    cout << "Enter number of months: ";
    cin >> n;

    Expenses e(n);

    for (int i = 0; i < n; i++)
    {
        double val;
        cout << "Enter expense for month " << i + 1 << ": ";
        cin >> val;
        e.setExpense(i, val);
    }

    cout << "Total expenses: " << e.total() << endl;
    cout << "Average expenses: " << e.average() << endl;

    char choice;
    cout << "Do you want to add more months? (y/n): ";
    cin >> choice;

    if (choice == 'y')
    {
        int extra;
        cout << "Enter additional months: ";
        cin >> extra;

        int oldSize = e.getSize();
        e.resize(oldSize + extra);

        for (int i = oldSize; i < oldSize + extra; i++)
        {
            double val;
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> val;
            e.setExpense(i, val);
        }

        cout << "Updated total expenses: " << e.total() << endl;
        cout << "Updated average expenses: " << e.average() << endl;
    }

    return 0;
}