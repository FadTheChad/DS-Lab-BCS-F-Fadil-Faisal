#include <iostream>

using namespace std;

int main() 
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " numbers:\n";

    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }

    int target;

    cout << "Enter number to search: ";
    cin >> target;

    int index = -1;

    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] == target) 
        {
            index = i;
            break;
        }
    }

    if (index != -1) 
    {
        cout << target << " found at index " << index << endl;
    } 
    else 
    {
        cout << target << " not found" << endl;
    }

    return 0;
}