#include <iostream>
#include <string>

using namespace std;


// I didn't make a seperate class for book here, as the jagged array is supposed to store book IDs (given in question)
int main()
{
    int n;
    cout << "Enter number of categories: ";
    cin >> n;

    string* cats = new string[n];
    int* size = new int[n];
    int** books = new int*[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of category " << i + 1 << ": ";
        cin >> cats[i];

        cout << "Enter number of books in " << cats[i] << ": ";
        cin >> size[i];

        books[i] = new int[size[i]];
        cout << "Enter book IDs for " << cats[i] << ":\n";
        for (int j = 0; j < size[i]; j++)
            cin >> books[i][j];
    }

    int id;
    cout << "\nEnter book ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            if (books[i][j] == id)
            {
                cout << "Book " << id << " is in category " << cats[i] << endl;
                found = true;
            }
        }
    }

    if (!found)
        cout << "Book not found" << endl;

    for (int i = 0; i < n; i++)
        delete[] books[i];
    delete[] books;
    delete[] size;
    delete[] cats;

    return 0;
}