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

    void addData(int data)
    {
        Node *newNode = new Node(data);
        if (Head == nullptr)
        {
            Head = newNode;
            Tail = newNode;
            cout << "Data add successfully" << endl;
            return;
        }
        Tail->next = newNode;
        Tail = newNode;
        cout << "Data add successfully" << endl;
    }

    void printll()
    {
        Node *temp = Head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    Node *reverse(Node *head)
    {
        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    bool isPalindrome()
    {
        if (Head == nullptr || Head->next == nullptr)
            return true;

        Node *slow = Head;
        Node *fast = Head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverse(slow);
        Node *firstHalf = Head;

        while (secondHalf != nullptr)
        {
            if (firstHalf->data != secondHalf->data)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};

int main()
{
    LinkedList ll;
    ll.addData(1);
    ll.addData(2);
    ll.addData(3);
    ll.addData(2);
    ll.addData(1);
    ll.printll();
    if (ll.isPalindrome())
    {
        cout << "Linked List is Palindrome" << endl;
    }
    else
    {
        cout << "Linked List is not Palindrome" << endl;
    }
    return 0;
}