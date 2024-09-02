#include <iostream>
#include <vector>
using namespace std;

int min(vector<int> &nums)
{
    // int min = nums[0];
    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (min > nums[i])
    //     {
    //         min = nums[i];
    //     }
    // }
    // return min;

    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[right] < nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        return nums[left];
    }
}

int main()
{
    vector<int> nums;
    nums = {4, 5, 6, 7, 0, 1, 2};
    int result = min(nums);
    cout << result;

    return 0;
}