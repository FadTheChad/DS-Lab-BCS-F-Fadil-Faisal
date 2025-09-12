#include <iostream>

using namespace std;

int main() 
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    int employees[100];
    cout << "Enter " << n << " employee IDs (sorted):\n";

    for (int i = 0; i < n; i++) 
    {
        cin >> employees[i];
    }

    int regNo;
    cout << "Enter your roll number: ";
    cin >> regNo;

    int suffix = regNo % 100;

    int low = 0, high = n - 1, foundPos = -1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (employees[mid] % 100 == suffix) 
        {
            foundPos = mid;
            break;
        }
        else if (employees[mid] % 100 < suffix) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }

    if (foundPos != -1) 
    {
        cout << "Match found: Employee ID " << employees[foundPos] 
             << " at index " << foundPos << endl;
    } 
    else 
    {
        foundPos = low;
        int newID = (employees[0] / 100) * 100 + suffix;

        for (int j = n; j > foundPos; j--) 
        {
            employees[j] = employees[j - 1];
        }

        employees[foundPos] = newID;
        n++;

        cout << "No match found. Inserted new Employee ID " << newID 
             << " at index " << foundPos << endl;
    }

    cout << "Updated list: ";
    for (int i = 0; i < n; i++) 
    {
        cout << employees[i] << " ";
    }

    cout << endl;
    return 0;
}