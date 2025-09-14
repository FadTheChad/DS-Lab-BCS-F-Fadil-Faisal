#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) : data(val), next(nullptr), child(nullptr)
    {}
};

class MultiLevelList
{
public:
    Node* head;

    MultiLevelList()
    {
        head = nullptr;
    }

    void flatten()
    {
        Node* curr = head;

        while (curr)
        {
            if (curr->child)
            {
                Node* tempNext = curr->next;
                curr->next = curr->child;

                Node* childTail = curr->child;
                while (childTail->next) childTail = childTail->next;

                childTail->next = tempNext;

                curr->child = nullptr;
            }

            curr = curr->next;
        }
    }

    void printList()
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    MultiLevelList list;

    // Hardcoded multilevel list:
    // 1 -> 2 -> 3
    //      |
    //      4 -> 5

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n2->child = n4;
    n4->next = n5;

    list.head = n1;

    cout << "Original multilevel list: ";
    list.printList(); // only prints next pointers

    list.flatten();

    cout << "Flattened list: ";
    list.printList();

    return 0;
}