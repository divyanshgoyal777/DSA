#include <iostream>
#include <queue>
using namespace std;

queue<int> q1;
queue<int> q2;

void push(int n)
{
    q1.push(n);
}

int pop()
{
    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int a = q1.front();
    q1.pop();
    swap(q1, q2);
    return a;
}

int top()
{
    return q1.back();
}

void print()
{
    queue<int> temp = q1;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << '\n';
    queue<int> temp1 = q2;
    while (!temp1.empty())
    {
        cout << temp1.front() << " ";
        temp1.pop();
    }
    cout << '\n';
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();

    cout << top() << endl;
    print();

    cout << pop() << endl;
    print();

    cout << top() << endl;
    print();

    cout << pop() << endl;
    print();

    return 0;
}
