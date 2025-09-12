#include <iostream>

using namespace std;

int main() 
{
    int n;
    cout << "Enter size of dataset: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " account balances:\n";

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    bool sorted = true;
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] < arr[i - 1]) 
        {
            sorted = false;
            break;
        }
    }

    if (!sorted) 
    {
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (arr[j] > arr[j + 1]) 
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Data was not sorted. Sorted automatically.\n";
    }

    bool uniform = true;
    int diff = arr[1] - arr[0];
    for (int i = 2; i < n; i++) 
    {
        if (arr[i] - arr[i - 1] != diff) 
        {
            uniform = false;
            break;
        }
    }

    if (!uniform) 
    {
        cout << "Error: Data is not uniformly distributed.\n";
        return 0;
    }

    int target;
    cout << "Enter balance to search: ";
    cin >> target;

    int low = 0, high = n - 1, pos = -1;
    while (low <= high && target >= arr[low] && target <= arr[high]) 
    {
        int mid = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[mid] == target) 
        {
            pos = mid;
            break;
        }
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }

    if (pos != -1) 
    {
        cout << "Balance " << target << " found at index " << pos << endl;
    }
    else 
    {
        cout << "Balance " << target << " not found.\n";
    }

    return 0;
}