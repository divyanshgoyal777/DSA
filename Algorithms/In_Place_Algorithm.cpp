#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    reverseArray(arr, n);
    cout << "Reversed array is" << endl;
    printArray(arr, n);
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int partition(vector<int> &arr, int low, int high)
// {
//     int pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// void quickSort(vector<int> &arr, int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main()
// {
//     vector<int> arr = {10, 7, 8, 9, 1, 5};
//     quickSort(arr, 0, arr.size() - 1);

//     for (int x : arr)
//         cout << x << " ";
//     return 0;
// }
