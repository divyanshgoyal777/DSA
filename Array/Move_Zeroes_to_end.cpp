#include <bits/stdc++.h>
using namespace std;

void moveZerosToEnd(vector<int> &arr)
{
    int nonZeroIndex = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[nonZeroIndex++], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZerosToEnd(arr);
    cout << "Array after moving zeros: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}
