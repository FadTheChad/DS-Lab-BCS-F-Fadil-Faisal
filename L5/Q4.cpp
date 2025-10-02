/* Task 4:
Write a C++ program that implements the Ackermann function, which is a classic example of
nested recursion. The function ackermann(int m, int n) is defined as:
● If m=0, return n+1.
● If m>0 and n=0, return ackermann(m-1, 1).
● If m>0 and n>0, return ackermann(m-1, ackermann(m, n-1)).
This task requires you to trace the execution and understand how one recursive call is a
parameter to another. */

#include <iostream>

using namespace std;

int ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }

    if (m > 0 && n == 0)
    {
        return ackermann(m - 1, 1);
    }

    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    int m, n;

    do
    {
        cout << "Enter value for m (must be >= 0): ";
        cin >> m;

        if (m >= 0) break;
        cout << "Invalid input. m cannot be negative!" << endl;
    } 
    while (m < 0);

    cout << endl;

    do
    {
        cout << "Enter value for n (must be >= 0): ";
        cin >> n;

        if (n >= 0) break;
        cout << "Invalid input. n cannot be negative!" << endl;
    } 
    while (n < 0);

    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;

    return 0;
}
