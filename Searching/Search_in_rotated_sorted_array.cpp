#include <iostream>
using namespace std;

int binarySearch(int arr[], int si, int ei, int target)
{
    if (si > ei)
        return -1;

    int mid = si + (ei - si) / 2;

    // Case 1: Target found
    if (arr[mid] == target)
        return mid;

    // Case 2: Target on line 1
    else if (arr[mid] >= arr[si])
    {
        // Target on left of line 1
        if (arr[si] <= target && target <= arr[mid])
            return binarySearch(arr, si, mid - 1, target);
        else
            return binarySearch(arr, mid + 1, ei, target);
    }

    // Case 3: target on line 2
    else
    {
        // Target of right of line 2
        if (arr[mid] <= target && target <= arr[ei])
            return binarySearch(arr, mid + 1, ei, target);
        else
            return binarySearch(arr, si, mid - 1, target);
    }
}

int main()
{
    int array[] = {4, 5, 6, 7, 0, 1, 2};
    int si = 0;
    int ei = 6;
    int target = 2;
    cout << binarySearch(array, 0, ei, target) << endl;

    return 0;
}