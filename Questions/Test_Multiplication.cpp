#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);
    int leftProduct = 1;
    for (int i = 0; i < n; ++i)
    {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
