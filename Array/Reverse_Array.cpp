#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr);
    cout << "Reversed Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}
