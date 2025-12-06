#include <iostream>
#include <algorithm>
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

    bool empty() const
    {
        return count == 0;
    }

    ~Stack()
    {
        while (head != nullptr)
        {
            Node<T>* old = head;
            head = head->link;
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
    else if (op == '*' || op == '/')
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

string infixToPrefix(string input)
{
    reverse(input.begin(), input.end());
    Stack<char> ops;
    string output = "";

    for (char &ch : input)
    {
        if (ch == '(')
        {
            ch = ')';
        }
        else if (ch == ')')
        {
            ch = '(';
        }
    }

    for (char ch : input)
    {
        if (isalnum(ch))
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
            while (!ops.empty() && (precedence(ch) < precedence(ops.top()) ||
                (precedence(ch) == precedence(ops.top()) && ch != '^')))
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

    reverse(output.begin(), output.end());
    return output;
}

double computePrefix(string expr)
{
    Stack<double> nums;
    reverse(expr.begin(), expr.end());

    for (char ch : expr)
    {
        if (isdigit(ch))
        {
            nums.push(ch - '0');
        }
        else
        {
            double left = nums.top();
            nums.pop();
            double right = nums.top();
            nums.pop();

            switch (ch)
            {
                case '+':
                    nums.push(right + left);
                    break;
                case '-':
                    nums.push(right - left);
                    break;
                case '*':
                    nums.push(right * left);
                    break;
                case '/':
                    nums.push(right / left);
                    break;
                case '^':
                    nums.push(pow(right, left));
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

    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    double answer = computePrefix(prefix);
    cout << "Result: " << answer << endl;

    return 0;
}
