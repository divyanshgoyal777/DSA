#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList
{
private:
    Node *head;

public:
    DoublyCircularLinkedList() : head(nullptr) {}

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
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
            Node *tail = head->prev;
            Node *temp = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
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
            Node *tail = head->prev;
            Node *newTail = tail->prev;
            newTail->next = head;
            head->prev = newTail;
            delete tail;
        }
    }

    void displayForward()
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

    void displayBackward()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *tail = head->prev;
        Node *temp = tail;
        do
        {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }
};

int main()
{
    DoublyCircularLinkedList dcll;
    dcll.insertAtEnd(10);
    dcll.insertAtEnd(20);
    dcll.insertAtBeginning(5);
    dcll.displayForward();
    dcll.displayBackward();
    dcll.deleteFromBeginning();
    dcll.displayForward();
    dcll.deleteFromEnd();
    dcll.displayForward();
    return 0;
}
