#include <iostream>

using namespace std;

/*
Task 1:
Write a recursive C++ function calculateFactorial(int n) that computes the factorial
of a given integer n . The function should have a base condition to stop the recursion when n is
0 or 1, and should call itself with a smaller value of n (e.g., n-1) to solve the problem.
*/

int calculateFactorial(int n)
{
    if (n < 0) throw "n cannot be negative";

    if (n == 1 || n == 0)
        return 1;

    return n * calculateFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Factorial: " << calculateFactorial(n);
}
