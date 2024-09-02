// PREFIX SUM

// The prefix sum of an array is an array where each element at index i contains the sum of all elements of the original array from index 0 to i.

// Example :   Original Array : [ 1, 2, 3, 4, 5 ]
//             Prefix Sum Array : [ 1, 3, 6, 10, 15 ]

// Formula : prefix_sum[𝑖] = arr[0] + arr[1] + ⋯ + arr[𝑖]

// SUFFIX SUM

// The suffix sum of an array is an array where each element at index i contains the sum of all elements of the original array from index i to the last index.

// Example :   Original Array : [ 1, 2, 3, 4, 5 ]
// Suffix Sum Array : [ 15, 14, 12, 9, 5 ]

// Formula : suffix_sum[i] = arr[i] + arr[i + 1] + ⋯ + arr[n − 1]

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    vector<int> prefix_sum(n, 0);
    vector<int> suffix_sum(n, 0);

    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    suffix_sum[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_sum[i] = suffix_sum[i + 1] + arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Prefix Sum Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix_sum[i] << " ";
    }
    cout << endl;

    cout << "Suffix Sum Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << suffix_sum[i] << " ";
    }
    cout << endl;

    return 0;
}
