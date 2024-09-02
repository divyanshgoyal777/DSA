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

    int removeLast()
    {
        if (Head == nullptr)
        {
            cout << "Linked List is empty" << endl;
            return -1;
        }
        if (Head == Tail)
        {
            int data = Head->data;
            delete Head;
            Head = Tail = nullptr;
            cout << data << " removed successfully from last" << endl;
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
        delete temp;
        Tail = prev;
        cout << data << " removed successfully from last" << endl;
        return data;
    }

    int removeStart()
    {
        if (Head == nullptr)
        {
            cout << "Linked List is empty" << endl;
            return -1;
        }
        Node *temp = Head;
        Head = Head->next;
        int data = temp->data;
        delete temp;
        if (Head == nullptr)
            Tail = nullptr;
        cout << data << " removed successfully from start" << endl;
        return data;
    }

    void addFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = Head;
        Head = newNode;
        if (Tail == nullptr)
            Tail = newNode;
        cout << data << " added to front successfully" << endl;
    }

    void addIndex(int data, int index)
    {
        if (index == 0)
        {
            addFront(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = Head;
        for (int i = 1; i < index; i++)
        {
            if (temp == nullptr)
            {
                cout << "Index is out of Linked List" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr)
            Tail = newNode;
        cout << data << " added at index " << index << " successfully" << endl;
    }

    void reverse()
    {
        Node *curr = Head;
        Node *next = nullptr;
        Node *prev = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Tail = Head;
        Head = prev;
        cout << "Linked list reversed successfully" << endl;
    }

    int findMiddle()
    {
        if (Head == nullptr)
        {
            cout << "Linked List is empty" << endl;
            return -1;
        }
        Node *slow = Head;
        Node *fast = Head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    int countNodes()
    {
        int count = 0;
        Node *temp = Head;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    int removeIndex(int index)
    {
        if (Head == nullptr)
        {
            cout << "Linked List is empty" << endl;
            return -1;
        }
        if (index == 0)
        {
            return removeStart();
        }
        Node *temp = Head;
        Node *prev = nullptr;
        for (int i = 0; i < index; i++)
        {
            if (temp == nullptr)
            {
                cout << "Index is out of bounds" << endl;
                return -1;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp->next == nullptr)
            Tail = prev;
        int data = temp->data;
        delete temp;
        cout << "Node at index " << index << " removed successfully" << endl;
        return data;
    }

    void createCycle()
    {
        if (Head == nullptr)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        int count = countNodes();
        Node *temp = Head;
        for (int i = 0; i < count - 4; i++)
        {
            temp = temp->next;
        }
        Tail->next = temp;
        cout << "Cycle created successfully" << endl;
    }

    int detectCycle()
    {
        if (Head == nullptr)
        {
            cout << "Linked List is empty" << endl;
            return 0;
        }
        Node *slow = Head;
        Node *fast = Head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return 1;
            }
        }
        return 0;
    }

    void removeElement(int data){
        if (Head == nullptr){
            cout << "Linked List is empty" << endl;
            return;
        }
        Node *temp = Head;
        Node *prev = nullptr;
        while (temp != nullptr){
            if (temp->data == data){
                if (prev == nullptr){
                    Head = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                cout << data << " removed successfully" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Element not found" << endl;
    }

    void removeCycle()
    {
        if (Head == nullptr)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        Node *slow = Head;
        Node *fast = Head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }

        if (slow == fast)
        {
            slow = Head;
            Node *prev = nullptr;
            while (slow != fast)
            {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            if (prev != nullptr)
            {
                prev->next = nullptr;
                cout << "Cycle removed successfully" << endl;
            }
        }
        else
        {
            cout << "No cycle found" << endl;
        }
    }
};

int main()
{
    LinkedList ll;
    ll.add(5);
    ll.add(3);
    ll.add(1);
    ll.add(2);
    ll.add(53);
    ll.add(57);
    ll.add(15);
    ll.add(50);
    ll.add(1);
    ll.printll();
    ll.removeElement(1);
    ll.printll();
    // ll.removeLast();
    // ll.printll();
    // ll.removeStart();
    // ll.printll();
    // ll.addFront(7);
    // ll.printll();
    // ll.addIndex(100, 3);
    // ll.printll();
    // ll.reverse();
    // ll.printll();
    // int middle = ll.findMiddle();
    // if (middle != -1)
    // {
    //     cout << "Middle element is: " << middle << endl;
    // }
    // int nodes = ll.countNodes();
    // cout << nodes << " are present" << endl;
    // ll.removeIndex(2);
    // ll.createCycle();
    // int detectcycle = ll.detectCycle();
    // if (detectcycle == 1)
    // {
    //     cout << "Cycle Detected" << endl;
    // }
    // else
    // {
    //     cout << "Cycle not detected" << endl;
    // }
    // ll.removeCycle();
    // ll.printll();
    return 0;
}
