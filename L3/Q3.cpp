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

    static Node* reverseKGroup(Node* head, int k)
    {
        if (head == nullptr || k <= 1)
        {
            return head;
        }

        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        int count = 0;
        Node* temp = head;
        while (temp != nullptr && count < k)
        {
            temp = temp->next;
            count++;
        }

        if (count < k)
        {
            return head;
        }

        count = 0;
        curr = head;
        while (curr != nullptr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != nullptr)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};

int main()
{
    LinkedList list;
    for (int i = 8; i >= 1; i--)
    {
        list.push(i);
    }

    list.head = LinkedList::reverseKGroup(list.head, 3);

    list.printList();

    return 0;
}