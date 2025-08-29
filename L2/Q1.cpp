#include <iostream>

using namespace std;

int main()
{
    int* arr;
    int n;

    cout << "Enter n: ";
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++) 
        arr[i] = 0;

    while (true)
    {
        int pos;

        cout << "Enter index to update (-1 to exit): ";
        cin >> pos;

        if (pos == -1) break;

        if (pos < 0 || pos >= n)
        {
            cout << "Invalid index" << endl;
            continue;
        }

        int val;
        
        cout << "Enter value: ";
        cin >> val;

        arr[pos] = val;
    }

    cout << "\nFINAL ARRAY: [";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != (n - 1)) cout << ", ";
    }

    cout << "]" << endl;
    
    delete[] arr;
}
