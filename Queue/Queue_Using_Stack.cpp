#include <iostream>
#include <stack>
using namespace std;

stack<int> s1;
stack<int> s2;

void enqueue(int value)
{
    s1.push(value);
}

int dequeue()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if (s2.empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int a = s2.top();
    s2.pop();
    return a;
}

int peek()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if (s2.empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return s2.top();
}

int main()
{
    enqueue(51);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(5);

    cout << "Peek: " << peek() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Peek: " << peek() << endl;

    return 0;
}
