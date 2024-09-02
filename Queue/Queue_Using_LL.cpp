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

    void addDataRear(int data)
    {
        Node *newNode = new Node(data);
        if (Head == nullptr)
        {
            Head = newNode;
            Tail = newNode;
            cout << "Data added successfully" << endl;
            return;
        }
        Tail->next = newNode;
        Tail = newNode;
        cout << "Data added successfully" << endl;
    }

    void printll()
    {
        Node *temp = Head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    void DeleteFront(){
        if(Head == nullptr){
            cout << "Linked List is empty" << endl;
            return;
        }
        Node *temp = Head;
        Head = Head->next;
        delete temp;
        cout << "Data removed successfully" << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.addDataRear(10);
    ll.addDataRear(20);
    ll.addDataRear(30);
    ll.printll();
    ll.DeleteFront();
    ll.printll();
    return 0;
}