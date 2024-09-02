#include <iostream>
using namespace std;

class LinkedList
{
public:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    Node *Head = NULL;
    Node *Tail = NULL;

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (Head == nullptr)
        {
            Head = Tail = newNode;
            cout << "Data pushed successfully" << endl;
            return;
        }
        Tail->next = newNode;
        Tail = newNode;
        cout << "Data pushed successfully" << endl;
    }

    int pop()
    {
        if (Head == Tail)
        {
            int data = Head->data;
            Head = Tail = nullptr;
            cout << "Data " << data << " popped successfully" << endl;
            return data;
        }
        Node *temp = Head;
        Node *prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        int data = temp->data;
        Tail = prev;
        cout << "Data " << data << " popped successfully" << endl;
        return data;
    }

    void peek()
    {
        Node *temp = Head;
        Node *prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        cout << temp->data << " is on top" << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.push(14);
    ll.push(41);
    ll.push(12);
    ll.push(31);
    ll.push(15);
    ll.push(13);
    ll.push(22);
    ll.pop();
    ll.pop();
    ll.pop();
    ll.pop();
    ll.pop();
    ll.peek();
    return 0;
}