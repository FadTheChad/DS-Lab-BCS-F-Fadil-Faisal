#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    double cost;
    string details;
    bool inStock;

    Product(const string &n, double p, const string &d, bool a) : name(n), cost(p), details(d), inStock(a)
    {
    }

    void show() const
    {
        cout << name << " - $" << cost;
        if (inStock)
        {
            cout << " | Available" << endl;
        }
        else
        {
            cout << " | Sold out" << endl;
        }
    }
};

int split(Product arr[], int low, int high)
{
    int i = low, j = high;
    Product pivot = arr[low];
    while (i < j)
    {
        while (i <= high - 1 && arr[i].cost <= pivot.cost)
        {
            i++;
        }
        while (j >= low + 1 && arr[j].cost > pivot.cost)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(Product arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int splitIndex = split(arr, start, end);
    quickSort(arr, start, splitIndex - 1);
    quickSort(arr, splitIndex + 1, end);
}

int main()
{
    const int count = 3;
    Product items[count] = {
        Product("Item 1", 10.99, "Description 1.", true),
        Product("Item 2", 5.99, "Description 2.", false),
        Product("Item 3", 2.99, "Description 3.", true)
    };

    quickSort(items, 0, count - 1);

    cout << "Items sorted by price:" << endl;
    for (int i = 0; i < count; ++i)
    {
        items[i].show();
    }

    return 0;
}
