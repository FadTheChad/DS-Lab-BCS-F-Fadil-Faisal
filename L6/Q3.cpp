#include <iostream>
using namespace std;

#define LIMIT 50

class Queue
{
    int data[LIMIT];
    int head, tail;

public:
    Queue() : head(-1), tail(-1)
    {
    }

    void enqueue(int num)
    {
        if (full())
        {
            cout << "Queue full! Cannot add" << endl;
            return;
        }

        if (head == -1)
        {
            head++;
        }
        data[++tail] = num;
        cout << num << " added to queue" << endl;
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue empty! Cannot remove" << endl;
            return;
        }

        int removed = data[head];

        if (head == tail)
        {
            head = -1;
            tail = -1;
        }
        else
        {
            head++;
        }

        cout << removed << " removed from queue" << endl;
    }

    void front() const
    {
        if (empty())
        {
            cout << "Queue empty!" << endl;
            return;
        }

        cout << "Front element: " << data[head] << endl;
    }

    void size() const
    {
        if (empty())
        {
            cout << "Queue size: 0" << endl;
        }
        else
        {
            cout << "Queue size: " << (tail - head + 1) << endl;
        }
    }

    bool empty() const
    {
        return (head == -1 || head > tail);
    }

    bool full() const
    {
        return (tail == LIMIT - 1);
    }

    void show() const
    {
        if (empty())
        {
            cout << "Queue empty!" << endl;
            return;
        }

        cout << "Queue contents: ";
        for (int i = head; i <= tail; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~Queue()
    {
    }
};

int main()
{
    Queue line;

    line.size();
    cout << "Queue empty? " << (line.empty() ? "Yes" : "No") << endl;
    line.enqueue(5);
    line.enqueue(10);
    line.size();
    line.front();
    cout << endl;

    line.enqueue(15);
    line.enqueue(20);
    line.dequeue();
    line.size();
    line.front();
    cout << endl;

    line.enqueue(30);
    line.enqueue(40);
    line.front();
    line.size();
    cout << "Queue empty? " << (line.empty() ? "Yes" : "No") << endl;
    line.show();

    return 0;
}
