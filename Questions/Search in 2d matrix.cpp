#include <iostream>
using namespace std;

int main()
{
    int matrix[3][4]= {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int rows = 3;
    int cols = 4;
    int left = 0;
    int right = rows * cols - 1;
    int target;
    cout << "Enter target: ";
    cin >> target;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int valueAtMid = matrix[mid / cols][mid % cols];
        if (valueAtMid == target)
        {
            cout << "Found " << valueAtMid << endl;
            return 0;
        }
        else if (valueAtMid < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "Not found" << endl;
    return 0;
}
