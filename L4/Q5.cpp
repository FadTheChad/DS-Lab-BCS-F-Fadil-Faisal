#include <iostream>

using namespace std;

int main()
{
    int n, target;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;
    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == target)
            {
                cout << "Index: " << low << endl;
            }
            else
            {
                cout << "Element not found" << endl;
            }
            found = true;
            break;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        if (arr[pos] == target)
        {
            cout << "Index: " << pos << endl;
            found = true;
            break;
        }

        if (arr[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    if (!found)
    {
        cout << "Element not found" << endl;
    }

    return 0;
}