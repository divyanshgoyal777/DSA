#include <iostream>
using namespace std;

void traverseArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertAtStart(int arr[], int &size, int value)
{
    for (int i = size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
    cout << "Inserted " << value << " at the start.\n";
}

void insertAtEnd(int arr[], int &size, int value)
{
    arr[size] = value;
    size++;
    cout << "Inserted " << value << " at the end.\n";
}

void insertAtIndex(int arr[], int &size, int index, int value)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid index.\n";
        return;
    }
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
    cout << "Inserted " << value << " at index " << index << ".\n";
}

void insertAtMiddle(int arr[], int &size, int value)
{
    int middle = size / 2;
    for (int i = size; i > middle; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[middle] = value;
    size++;
    cout << "Inserted " << value << " in the middle.\n";
}

void deleteFromStart(int arr[], int &size)
{
    if (size == 0)
    {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Deleted " << arr[0] << " from the start.\n";
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

void deleteFromEnd(int arr[], int &size)
{
    if (size == 0)
    {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Deleted " << arr[size - 1] << " from the end.\n";
    size--;
}

void deleteAtIndex(int arr[], int &size, int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Invalid index.\n";
        return;
    }
    cout << "Deleted " << arr[index] << " at index " << index << ".\n";
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

void deleteFromMiddle(int arr[], int &size)
{
    if (size == 0)
    {
        cout << "Array is empty.\n";
        return;
    }
    int middle = size / 2;
    cout << "Deleted " << arr[middle] << " from the middle.\n";
    for (int i = middle; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main()
{
    int arr[100];
    int size = 0;

    cout << "### Array Demonstration ###\n";

    insertAtEnd(arr, size, 10);
    insertAtEnd(arr, size, 20);
    insertAtEnd(arr, size, 30);
    traverseArray(arr, size);
    insertAtStart(arr, size, 5);
    traverseArray(arr, size);
    insertAtIndex(arr, size, 2, 15);
    traverseArray(arr, size);
    insertAtMiddle(arr, size, 25);
    traverseArray(arr, size);
    deleteFromStart(arr, size);
    traverseArray(arr, size);
    deleteFromEnd(arr, size);
    traverseArray(arr, size);
    deleteAtIndex(arr, size, 2);
    traverseArray(arr, size);
    deleteFromMiddle(arr, size);
    traverseArray(arr, size);

    return 0;
}
