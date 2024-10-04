#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int left, int right)
{
    int pi = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pi)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quicksort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 2, 6, 8, 7, 11, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}