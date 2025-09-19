#include <iostream>

using namespace std;

/*
Task 2:
1. Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly.
2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops.
*/

void printNumbers(int n)
{
    if (n <= 0) return;

    cout << n << endl;
    printNumbers(n - 1);
}

void functionB(int n);

void functionA(int n)
{
    if (n <= 0) return;

    cout << "A" << n << endl;

    functionB(n - 1);
}

void functionB(int n)
{
    if (n <= 0) return;

    cout << "B" << n << endl;

    functionA(n - 1);
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Numbers: " << endl;
    printNumbers(n);

    cout << endl << "INDIRECT RECURSION:" << endl;
    functionA(n);
}
