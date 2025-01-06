#include <bits/stdc++.h>
using namespace std;

int findMin(const vector<int> &arr)
{
    int minVal = INT_MAX;
    for (int num : arr)
    {
        minVal = min(minVal, num);
    }
    return minVal;
}

int findMax(const vector<int> &arr)
{
    int maxVal = INT_MIN;
    for (int num : arr)
    {
        maxVal = max(maxVal, num);
    }
    return maxVal;
}

int main()
{
    vector<int> arr = {12, 3, 7, 9, 15};
    int minVal = findMin(arr);
    int maxVal = findMax(arr);
    cout << "Minimum: " << minVal << "\nMaximum: " << maxVal << endl;
    return 0;
}
