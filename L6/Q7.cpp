#include <iostream>
using namespace std;

const int LIMIT = 100;

class Queue
{
    int items[LIMIT];
    int head, tail;

public:
    Queue()
    {
        head = tail = -1;
    }

    bool empty()
    {
        return (head == -1 || head > tail);
    }

    bool full()
    {
        return tail == LIMIT - 1;
    }

    void add(int val)
    {
        if (full())
        {
            return;
        }
        if (head == -1)
        {
            head = 0;
        }
        items[++tail] = val;
    }

    int remove()
    {
        if (empty())
        {
            return -1;
        }
        return items[head++];
    }

    int front()
    {
        if (empty())
        {
            return -1;
        }
        return items[head];
    }

    void clear()
    {
        head = tail = -1;
    }

    void show()
    {
        if (empty())
        {
            cout << "Queue empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = head; i <= tail; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    friend class Scheduler;
};

class Stack
{
    int items[LIMIT];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool empty()
    {
        return (top == -1);
    }

    bool full()
    {
        return (top == LIMIT - 1);
    }

    void push(int val)
    {
        if (full())
        {
            return;
        }
        items[++top] = val;
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }
        return items[top--];
    }

    void show()
    {
        if (empty())
        {
            cout << "Stack empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

struct Task
{
    int id;
    int rank;
};

class Scheduler
{
    Queue arrival;
    Stack execution;

public:
    void start()
    {
        cout << "=== Job Scheduler ===\n\n";

        Task jobs[] =
        {
            {101, 2}, {102, 1}, {103, 3}, {104, 2}, {105, 3}
        };

        cout << "1. Tasks arriving:\n";
        for (int i = 0; i < 5; i++)
        {
            arrival.add(jobs[i].id * 10 + jobs[i].rank);
            cout << "Task " << jobs[i].id
                 << " (Rank " << jobs[i].rank << ") arrived\n";
        }
        arrival.show();

        cout << "\n2. Moving high rank tasks to stack:\n";
        int top_rank = 0;

        for (int i = arrival.head; i <= arrival.tail; i++)
        {
            int data = arrival.items[i];
            int rank = data % 10;
            if (rank > top_rank)
            {
                top_rank = rank;
            }
        }
        cout << "Top rank: " << top_rank << endl;

        Queue wait;

        while (!arrival.empty())
        {
            int data = arrival.remove();
            int taskId = data / 10;
            int rank = data % 10;

            if (rank == top_rank)
            {
                execution.push(data);
                cout << "High rank task " << taskId << " to stack\n";
            }
            else
            {
                wait.add(data);
            }
        }

        cout << "\n3. Execution order (LIFO):\n";
        execution.show();

        cout << "\n4. Running tasks:\n";
        while (!execution.empty())
        {
            int data = execution.pop();
            int taskId = data / 10;
            int rank = data % 10;
            cout << "Running Task " << taskId << " (Rank " << rank << ")\n";
        }

        cout << "\n5. Remaining tasks:\n";
        wait.show();

        cout << "\n=== End ===\n";
    }
};

int main()
{
    Scheduler sys;
    sys.start();
    return 0;
}
