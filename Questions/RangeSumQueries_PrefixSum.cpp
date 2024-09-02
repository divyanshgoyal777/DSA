#include <iostream>
#include <vector>

using namespace std;

vector<int> computePrefixSum(const vector<int> &arr)
{
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

int querySum(const vector<int> &prefix, int l, int r)
{
    if (l == 0)
        return prefix[r];
    return prefix[r] - prefix[l - 1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefix = computePrefixSum(arr);
    int l = 1, r = 4;
    cout << "Sum of elements from index " << l << " to " << r << " is: " << querySum(prefix, l, r) << endl;

    return 0;
}
