#include <iostream>
using namespace std;

class Node
{
public:
    string info;
    Node* link;

    Node(string val) : info(val), link(nullptr)
    {
    }
};

class Stack
{
    Node* head;
    int count;

public:
    Stack() : head(nullptr), count(0)
    {
    }

    void push(string val)
    {
        Node* fresh = new Node(val);
        fresh->link = head;
        head = fresh;
        count++;
        cout << val << " added to history" << endl;
    }

    void pop()
    {
        if (count == 0)
        {
            cout << "No history to go back" << endl;
            return;
        }

        string removed = head->info;
        Node* old = head;
        head = head->link;
        delete old;
        count--;
        cout << "Back to: " << removed << endl;
    }

    void peek() const
    {
        if (count == 0)
        {
            cout << "History empty" << endl;
            return;
        }

        cout << "Current page: " << head->info << endl;
    }

    void size() const
    {
        cout << "History size: " << count << endl;
    }

    void show() const
    {
        if (count == 0)
        {
            cout << "History empty" << endl;
            return;
        }

        Node* curr = head;
        cout << "Browser history: " << endl;
        while (curr != nullptr)
        {
            cout << curr->info << " <- ";
            curr = curr->link;
        }
        cout << "START" << endl;
    }

    ~Stack()
    {
        Node* curr = head;
        while (curr != nullptr)
        {
            Node* old = curr;
            curr = curr->link;
            delete old;
        }
    }
};

int main()
{
    Stack history;

    history.size();
    history.push("google.com");
    history.push("youtube.com");
    history.size();
    history.peek();
    cout << endl;

    history.push("github.com");
    history.push("stackoverflow.com");
    history.pop();
    history.size();
    history.peek();
    cout << endl;

    history.push("wikipedia.org");
    history.push("reddit.com");
    history.peek();
    history.size();
    history.show();

    return 0;
}
