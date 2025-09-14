#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr)
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

    void printList()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    static Node* merge(Node* l1, Node* l2)
    {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        Node* head = nullptr;
        Node* tail = nullptr;

        if (l1->data <= l2->data)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }

        tail = head;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->data <= l2->data)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1 != nullptr) tail->next = l1;
        if (l2 != nullptr) tail->next = l2;

        return head;
    }
};

int main() //Iss mai yeh assumption hai keh both lists are already in ascending order
{
    LinkedList list1;
    list1.push(7);
    list1.push(5);
    list1.push(3);
    list1.push(1);

    LinkedList list2;
    list2.push(8);
    list2.push(6);
    list2.push(4);
    list2.push(2);

    Node* mergedHead = LinkedList::merge(list1.head, list2.head);

    Node* temp = mergedHead;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}