// Divide and Conquer is an algorithmic paradigm where a problem is divided into smaller subproblems of the same type, each of which is solved independently.The solutions to the subproblems are then combined to form the solution to the original problem.

#include <iostream>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    using namespace std;

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// void merge(vector<int> &arr, int left, int mid, int right)
// {
//     vector<int> temp(right - left + 1);

//     int i = left, j = mid + 1, k = 0;

//     while (i <= mid && j <= right)
//     {
//         if (arr[i] <= arr[j])
//         {
//             temp[k++] = arr[i++];
//         }
//         else
//         {
//             temp[k++] = arr[j++];
//         }
//     }

//     while (i <= mid)
//     {
//         temp[k++] = arr[i++];
//     }

//     while (j <= right)
//     {
//         temp[k++] = arr[j++];
//     }

//     for (int i = 0; i < temp.size(); ++i)
//     {
//         arr[left + i] = temp[i];
//     }
// }

// void mergeSort(vector<int> &arr, int left, int right)
// {
//     if (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// int main()
// {
//     vector<int> arr = {12, 11, 13, 5, 6, 7};

//     cout << "Given array is: ";
//     for (int num : arr)
//         cout << num << " ";
//     cout << endl;

//     mergeSort(arr, 0, arr.size() - 1);

//     cout << "Sorted array is: ";
//     for (int num : arr)
//         cout << num << " ";
//     cout << endl;

//     return 0;
// }
