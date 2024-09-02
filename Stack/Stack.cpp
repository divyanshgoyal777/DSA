#include <iostream>
using namespace std;

#define SIZE 10

class Stack
{
private:
    int array[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int n)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        array[++top] = n;
        cout << n << " is pushed in stack" << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int n = array[top--];
        cout << n << " is popped" << endl;
    }

    void getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty, no top value exists" << endl;
            return;
        }
        cout << array[top] << " is top value in stack" << endl;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.getTop();
    s.push(6);
    s.push(7);
    s.push(7);
    s.push(7);
    s.push(7);
    s.getTop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.getTop();
    s.pop();
    s.pop();
    s.pop();
    s.getTop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.getTop();

    return 0;
}
