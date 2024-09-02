#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void insertFront(int data) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = data;
        size++;
    }

    void insertRear(int data) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = data;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }

        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(3);
    dq.insertFront(4);
    dq.insertRear(5);

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteFront();
    dq.deleteRear();

    cout << "After deletion, Front element: " << dq.getFront() << endl;
    cout << "After deletion, Rear element: " << dq.getRear() << endl;

    return 0;
}
