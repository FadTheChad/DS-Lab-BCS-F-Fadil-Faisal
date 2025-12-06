#include <iostream>
using namespace std;

#define CAPACITY 50

class Stack
{
    int data[CAPACITY];
    int head;

public:
    Stack() : head(-1)
    {
    }

    void push(int num)
    {
        if (head >= CAPACITY - 1)
        {
            cout << "Stack full! Push operation failed" << endl;
            return;
        }

        data[++head] = num;
        cout << num << " added to stack" << endl;
    }

    void pop()
    {
        if (head == -1)
        {
            cout << "Stack empty! Pop operation failed" << endl;
            return;
        }

        int removed = data[head];
        head--;
        cout << removed << " removed from stack" << endl;
    }

    void peek() const
    {
        if (head == -1)
        {
            cout << "Stack empty!" << endl;
            return;
        }

        cout << "Top element is: " << data[head] << endl;
    }

    void show() const
    {
        if (head == -1)
        {
            cout << "Stack empty!" << endl;
            return;
        }

        cout << "Stack contents: ";
        for (int i = head; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void size() const
    {
        cout << "Stack size: " << head + 1 << endl;
    }

    ~Stack()
    {
    }
};

int main()
{
    Stack stk;

    stk.size();
    stk.push(5);
    stk.push(10);
    stk.size();
    stk.peek();
    cout << endl;

    stk.push(15);
    stk.push(20);
    stk.pop();
    stk.size();
    stk.peek();
    cout << endl;

    stk.push(30);
    stk.push(40);
    stk.peek();
    stk.size();
    stk.show();

    return 0;
}
