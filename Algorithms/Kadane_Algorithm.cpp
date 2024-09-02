#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0], currSum = nums[0];    

    for (size_t i = 1; i < nums.size(); i++)
    {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout << "Max subarray sum: " << maxSubArray(nums) << endl;
    return 0;
}
