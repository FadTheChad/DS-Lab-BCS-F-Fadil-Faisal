#include <iostream>
using namespace std;

// Singly linked list node
class Node
{
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr)
    {}
};

// Doubly linked list node
class DNode
{
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode() : data(0), next(nullptr), prev(nullptr)
    {}
};

// Circular linked list node (same as singly)
class CNode
{
public:
    int data;
    CNode* next;

    CNode() : data(0), next(nullptr)
    {}
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    void push(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void printSingly()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 1. Convert singly linked list → doubly linked list
    DNode* toDoublyLinkedList()
    {
        if (head == nullptr) return nullptr;

        DNode* dHead = new DNode();
        dHead->data = head->data;
        DNode* prev = dHead;
        Node* temp = head->next;

        while (temp != nullptr)
        {
            DNode* newNode = new DNode();
            newNode->data = temp->data;
            newNode->prev = prev;
            prev->next = newNode;
            prev = newNode;
            temp = temp->next;
        }

        return dHead;
    }

    // 2. Convert singly linked list → circular linked list
    CNode* toCircularLinkedList()
    {
        if (head == nullptr) return nullptr;

        CNode* cHead = new CNode();
        cHead->data = head->data;
        CNode* prev = cHead;
        Node* temp = head->next;

        while (temp != nullptr)
        {
            CNode* newNode = new CNode();
            newNode->data = temp->data;
            prev->next = newNode;
            prev = newNode;
            temp = temp->next;
        }

        prev->next = cHead; // Make it circular
        return cHead;
    }
};

// Utility functions to print new lists
void printDoublyList(DNode* head)
{
    DNode* temp = head;
    cout << "Forward: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        if (temp->next == nullptr) break;
        temp = temp->next;
    }
    cout << endl;

    cout << "Backward: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void printCircularList(CNode* head, int n)
{
    CNode* temp = head;
    for (int i = 0; i < n; i++)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    LinkedList list;
    list.push(5);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);

    cout << "Original singly linked list: ";
    list.printSingly();

    DNode* dList = list.toDoublyLinkedList();
    cout << "Doubly linked list:" << endl;
    printDoublyList(dList);

    CNode* cList = list.toCircularLinkedList();
    cout << "Circular linked list: ";
    printCircularList(cList, 5); // print 5 nodes to show circularity

    return 0;
}