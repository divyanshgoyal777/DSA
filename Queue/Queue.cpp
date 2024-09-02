#include <iostream>
using namespace std;

class Queue
{
    static const int SIZE = 10;
    int array[SIZE];
    int front, rear;

public:

    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isfull()
    {
        return rear == SIZE - 1;
    }

    bool isempty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(int n)
    {
        if (isfull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        array[++rear] = n;
        cout << n << " is enqueued" << endl;
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << array[front++] << " is dequeued" << endl;
        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void nelements()
    {
        if (isempty())
        {
            cout << "Total elements in queue - 0" << endl;
        }
        else
        {
            cout << "Total elements in queue - " << rear - front + 1 << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    q.nelements();
    cout << "Is queue full? " << (q.isfull() ? "Yes" : "No") << endl;
    cout << "Is queue empty? " << (q.isempty() ? "Yes" : "No") << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(8);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "Is queue full? " << (q.isfull() ? "Yes" : "No") << endl;
    cout << "Is queue empty? " << (q.isempty() ? "Yes" : "No") << endl;
    q.nelements();
    return 0;
}
