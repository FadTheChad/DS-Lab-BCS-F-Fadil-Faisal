#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int grade;
};

struct Node
{
    Student person;
    Node* next;

    Node(Student s, Node* n = nullptr) : person(s), next(n)
    {
    }
};

void addNode(Node*& head, const Student& s)
{
    Node* fresh = new Node(s);

    if (!head)
    {
        head = fresh;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = fresh;
}

void showList(Node* head)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        cout << "Name: " << curr->person.name << " | Grade: " << curr->person.grade << endl;
        curr = curr->next;
    }
    cout << endl;
}

void wipeBucket(Node*& head)
{
    Node* temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void radixSort(Node*& head, const int n)
{
    if (!head || !head->next)
    {
        return;
    }

    int exp = 1;
    int limit = 100;

    Node* buckets[10];

    while (limit / exp > 0)
    {
        for (int i = 0; i < 10; i++)
        {
            buckets[i] = nullptr;
        }

        Node* curr = head;
        for (int i = 0; i < n; i++)
        {
            int digit = (curr->person.grade / exp) % 10;
            addNode(buckets[digit], curr->person);
            curr = curr->next;
        }

        wipeBucket(head);
        for (int i = 0; i < 10; i++)
        {
            Node* temp = buckets[i];
            while (temp != nullptr)
            {
                addNode(head, temp->person);
                temp = temp->next;
            }

            wipeBucket(buckets[i]);
        }

        exp *= 10;
    }
}

Student* listToArray(Node* head, int n)
{
    Student* arr = new Student[n];
    Node* curr = head;
    int idx = 0;
    while (curr != nullptr)
    {
        arr[idx++] = curr->person;
        curr = curr->next;
    }

    return arr;
}

int binaryFind(const Student* arr, int n, const string& name, int grade)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid].grade == grade)
        {
            if (arr[mid].name == name)
            {
                return mid;
            }

            int i = mid - 1;
            while (i >= left && arr[i].grade == grade)
            {
                if (arr[i].name == name)
                {
                    return i;
                }
                i--;
            }

            i = mid + 1;
            while (i <= right && arr[i].grade == grade)
            {
                if (arr[i].name == name)
                {
                    return i;
                }
                i++;
            }

            return -1;
        }
        else if (arr[mid].grade < grade)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void removeRecord(Node*& head, const string& name, int grade)
{
    Node* curr = head;
    Node* prev = nullptr;

    while (curr)
    {
        if (curr->person.name == name && curr->person.grade == grade)
        {
            if (!prev)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            delete curr;
            cout << "Record removed." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Record not found." << endl;
}

int main()
{
    int n;
    cout << "Enter student count: ";
    cin >> n;
    cin.ignore();
    cout << endl;

    Node* head = nullptr;
    for (int i = 0; i < n; i++)
    {
        Student person;
        cout << "Enter name of student " << (i + 1) << ": ";
        getline(cin, person.name);
        do
        {
            cout << "Enter grade (0-100) of student " << (i + 1) << ": ";
            cin >> person.grade;
            cin.ignore();

            if (person.grade < 0 || person.grade > 100)
            {
                cout << "Invalid grade!" << endl;
            }
        }
        while (person.grade < 0 || person.grade > 100);

        addNode(head, person);
        cout << endl;
    }

    cout << "\n--- Original List ---\n";
    showList(head);

    radixSort(head, n);

    cout << "\n--- Sorted List ---\n";
    showList(head);

    string name;
    int grade;
    cout << "\nEnter name & grade to find and remove: ";
    getline(cin, name);
    cin >> grade;

    Student* arr = listToArray(head, n);
    int idx = binaryFind(arr, n, name, grade);

    if (idx != -1)
    {
        removeRecord(head, name, grade);

        cout << "\n--- Updated List ---\n";
        showList(head);
    }
    else
    {
        cout << endl
             << "Record not found." << endl;
    }

    return 0;
}
