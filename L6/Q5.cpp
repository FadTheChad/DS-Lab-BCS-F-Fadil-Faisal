#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Node
{
public:
    T info;
    Node<T>* link;

    Node(T val) : info(val), link(nullptr)
    {
    }
};

template <typename T>
class Stack
{
    Node<T>* head;
    int count;

public:
    Stack() : head(nullptr), count(0)
    {
    }

    void push(T val)
    {
        Node<T>* fresh = new Node<T>(val);
        fresh->link = head;
        head = fresh;
        count++;
    }

    void pop()
    {
        if (count == 0)
        {
            return;
        }

        Node<T>* old = head;
        head = head->link;
        delete old;
        count--;
    }

    T top() const
    {
        if (count == 0)
        {
            return '-';
        }

        return head->info;
    }

    int length() const
    {
        return count;
    }

    bool empty() const
    {
        return count == 0;
    }

    ~Stack()
    {
        Node<T>* curr = head;
        while (curr != nullptr)
        {
            Node<T>* old = curr;
            curr = curr->link;
            delete old;
        }
    }
};

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '/' || op == '*')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string input)
{
    string output = "";
    Stack<char> ops;

    for (char ch : input)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            output += ch;
        }
        else if (ch == '(')
        {
            ops.push(ch);
        }
        else if (ch == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                output += ops.top();
                ops.pop();
            }

            if (!ops.empty())
            {
                ops.pop();
            }
        }
        else
        {
            while (!ops.empty() && ((precedence(ch) < precedence(ops.top()) || (precedence(ch) == precedence(ops.top()) && ch != '^'))))
            {
                output += ops.top();
                ops.pop();
            }
            ops.push(ch);
        }
    }

    while (!ops.empty())
    {
        output += ops.top();
        ops.pop();
    }

    return output;
}

double computePostfix(string expr)
{
    Stack<double> nums;
    for (char ch : expr)
    {
        if (isdigit(ch))
        {
            nums.push(ch - '0');
        }
        else
        {
            double right = nums.top();
            nums.pop();
            double left = nums.top();
            nums.pop();
            switch (ch)
            {
                case '+':
                    nums.push(left + right);
                    break;
                case '-':
                    nums.push(left - right);
                    break;
                case '*':
                    nums.push(left * right);
                    break;
                case '/':
                    nums.push(left / right);
                    break;
                case '^':
                    nums.push(pow(left, right));
                    break;
            }
        }
    }

    return nums.top();
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    double answer = computePostfix(postfix);
    cout << "Result: " << answer << endl;

    return 0;
}
