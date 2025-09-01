#include <iostream>
using namespace std;

class SafePointer
{
    int* ptr;

public:
    SafePointer()
    {
        ptr = new int;
    }

    ~SafePointer()
    {
        delete ptr;
    }

    void setValue(int val)
    {
        *ptr = val;
    }

    int getValue()
    {
        return *ptr;
    }

    // Not exactly sure what 'release' is supposed to mean here. So i did this. 
    int* release()
    {
        int* temp = ptr;
        ptr = nullptr;
        return temp;
    }
};

int main()
{
    int n = 5;
    SafePointer* marks = new SafePointer[n];

    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> val;
        marks[i].setValue(val);
    }

    cout << "Stored marks:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": " << marks[i].getValue() << endl;
    }

    delete[] marks;
    return 0;
}