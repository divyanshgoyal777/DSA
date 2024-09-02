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
            this->next = nullptr;
        }
    };
    Node *Head = nullptr;
    Node *Tail = nullptr;

    void add(int data)
    {
        Node *newNode = new Node(data);
        if (Head == nullptr)
        {
            Head = Tail = newNode;
            cout << "Data added successfully" << endl;
            return;
        }
        Tail->next = newNode;
        Tail = newNode;
        cout << "Data added successfully" << endl;
    }

    bool found(Node *Head, int key)
    {
        if (Head == nullptr)
        {
            return false;
        }
        if (Head->data == key)
        {
            return true;
        }
        return found(Head->next, key);
    }
    
    bool search(int key)
    {
        return found(Head, key);
    }
};

int main()
{
    LinkedList ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    if (ll.search(3))
    {
        cout << "Data Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}