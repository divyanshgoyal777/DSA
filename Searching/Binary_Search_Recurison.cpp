#include <iostream>
#include <vector>

int binarySearchRecursive(const std::vector<int> &nums, int target, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[mid] > target)
    {
        return binarySearchRecursive(nums, target, left, mid - 1);
    }
    else
    {
        return binarySearchRecursive(nums, target, mid + 1, right);
    }
}

int binarySearch(const std::vector<int> &nums, int target)
{
    return binarySearchRecursive(nums, target, 0, nums.size() - 1);
}

int main()
{
    std::vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;

    int index = binarySearch(nums, target);

    if (index != -1)
    {
        std::cout << "Target found at index: " << index << std::endl;
    }
    else
    {
        std::cout << "Target not found" << std::endl;
    }

    return 0;
}
