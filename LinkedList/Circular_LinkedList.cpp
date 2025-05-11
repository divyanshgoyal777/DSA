#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void deleteFromBeginning()
    {
        if (!head)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            Node *last = head;
            while (last->next != head)
                last = last->next;
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    void deleteFromEnd()
    {
        if (!head)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            Node *prev = nullptr;
            while (temp->next != head)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.display();
    cll.deleteFromBeginning();
    cll.display();
    cll.deleteFromEnd();
    cll.display();
    return 0;
}
