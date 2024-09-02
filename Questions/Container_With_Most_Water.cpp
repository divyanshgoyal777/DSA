#include <iostream>
#include <algorithm>
using namespace std;

int mostRectangle(int height[], int size)
{
    int left = 0;
    int right = size - 1;
    int max_area = 0;

    while (left < right)
    {
        int left_height = height[left];
        int right_height = height[right];
        int min_height = min(left_height, right_height);
        int width = right - left;
        int current_area = min_height * width;
        max_area = max(max_area, current_area);

        if (left_height < right_height)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max_area;
}

int main()
{
    int array[] = {2, 3, 4, 5, 18, 17, 6};
    int size = sizeof(array) / sizeof(array[0]);
    int res = mostRectangle(array, size);
    cout << "The maximum area is: " << res << std::endl;
    return 0;
}
