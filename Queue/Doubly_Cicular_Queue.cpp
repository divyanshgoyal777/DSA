#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyCircularQueue
{
private:
    Node *front;
    Node *rear;

public:
    DoublyCircularQueue()
    {
        front = rear = nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (!front)
        {
            front = rear = newNode;
            front->next = front->prev = front;
        }
        else
        {
            newNode->prev = rear;
            newNode->next = front;
            rear->next = newNode;
            front->prev = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        int value = front->data;
        if (front == rear)
        {
            delete front;
            front = rear = nullptr;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            front->prev = rear;
            rear->next = front;
            delete temp;
        }
        cout << "Dequeued: " << value << endl;
    }

    void display()
    {
        if (!front)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *temp = front;
        cout << "Queue: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main()
{
    DoublyCircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
