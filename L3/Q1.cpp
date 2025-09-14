#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(): data(0), next(nullptr)
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

    Node* reverse(Node* node)
    {
        Node* prev = nullptr;
        Node* curr = node;
        Node* next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverse(slow->next);
        Node* firstHalf = head;
        Node* copySecondHalf = secondHalf;

        bool result = true;
        while (result && secondHalf != nullptr)
        {
            if (firstHalf->data != secondHalf->data)
            {
                result = false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        slow->next = reverse(copySecondHalf);

        return result;
    }
};

int main()
{
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(2);
    list.push(1);

    if (list.isPalindrome())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}