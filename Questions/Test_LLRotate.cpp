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
        Node(int data) : data(data), next(nullptr) {}
    };

    Node *Head;
    Node *Tail;

    LinkedList() : Head(nullptr), Tail(nullptr) {}

    void add(int data)
    {
        Node *newNode = new Node(data);
        if (Head == nullptr)
        {
            Head = Tail = newNode;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
        }
        cout << "Data added successfully" << endl;
    }

    void rotateRight(int k)
    {
        if (!Head || k == 0)
            return;

        Node *current = Head;
        int length = 1;
        while (current->next)
        {
            current = current->next;
            length++;
        }

        k = k % length;
        if (k == 0)
            return;

        Node *newTail = Head;
        for (int i = 1; i < length - k; i++)
        {
            newTail = newTail->next;
        }
        Node *newHead = newTail->next;

        current->next = Head;
        newTail->next = nullptr;

        Head = newHead;
        Tail = newTail;
    }

    void printList()
    {
        Node *current = Head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        while (Head)
        {
            Node *temp = Head;
            Head = Head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "Original list: ";
    list.printList();

    list.rotateRight(2);

    cout << "Rotated list: ";
    list.printList();

    return 0;
}
