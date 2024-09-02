#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int elem = arr[i];
        int j = i - 1;
        while (j >= 0 && elem < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = elem;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {2, 5, 31, 21, 5, 32, 12};
    int size = sizeof(array) / sizeof(array[0]);
    insertionSort(array, size);
    return 0;
}
