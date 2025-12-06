#include <iostream>
using namespace std;

#define LIMIT 5

class CircularQueue
{
    int data[LIMIT];
    int head, tail;
    int count;

public:
    CircularQueue() : head(-1), tail(-1), count(0)
    {
    }

    void enqueue(int num)
    {
        if (full())
        {
            cout << "Queue full! Cannot enqueue" << endl;
            return;
        }

        if (count == 0)
        {
            head = 0;
            tail = 0;
        }
        else
        {
            tail = (tail + 1) % LIMIT;
        }

        data[tail] = num;
        count++;
        cout << num << " added to queue" << endl;
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue empty! Cannot dequeue" << endl;
            return;
        }

        int removed = data[head];
        if (count == 1)
        {
            head = -1;
            tail = -1;
        }
        else
        {
            head = (head + 1) % LIMIT;
        }
        
        count--;
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

    bool empty() const
    {
        return count == 0;
    }

    bool full() const
    {
        return count == LIMIT;
    }

    void size() const
    {
        cout << "Queue size: " << count << endl;
    }

    void show() const
    {
        if (empty())
        {
            cout << "Queue empty!" << endl;
            return;
        }

        cout << "Queue contents: ";
        for (int i = 0; i < count; i++)
        {
            cout << data[(head + i) % LIMIT] << " ";
        }
        cout << endl;
    }

    ~CircularQueue()
    {
    }
};

int main()
{
    CircularQueue circle;

    circle.size();
    cout << "Queue empty? " << (circle.empty() ? "Yes" : "No") << endl;
    circle.enqueue(5);
    circle.enqueue(10);
    circle.size();
    circle.front();
    cout << endl;

    circle.enqueue(15);
    circle.enqueue(20);
    circle.dequeue();
    circle.size();
    circle.front();
    cout << endl;

    circle.enqueue(30);
    circle.enqueue(40);
    circle.enqueue(50);
    circle.front();
    circle.size();
    cout << "Queue empty? " << (circle.empty() ? "Yes" : "No") << endl;
    circle.show();

    return 0;
}
