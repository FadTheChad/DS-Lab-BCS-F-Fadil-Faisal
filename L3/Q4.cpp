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

class CircularLinkedList
{
public:
    Node* head;

    CircularLinkedList()
    {
        head = nullptr;
    }

    void push(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    int getJosephusPosition(int k)
    {
        Node* ptr = head;
        Node* prev = nullptr;

        while (ptr->next != ptr)
        {
            for (int count = 1; count < k; count++)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = ptr->next;
            Node* toDelete = ptr;
            ptr = ptr->next;
            delete toDelete;
        }

        int survivor = ptr->data;
        delete ptr;
        return survivor;
    }
};

int main()
{
    int N = 7;
    int k = 3;

    CircularLinkedList list;
    for (int i = N; i >= 1; i--)
    {
        list.push(i);
    }

    int survivor = list.getJosephusPosition(k);

    cout << "Survivor position: " << survivor << endl;

    return 0;
}