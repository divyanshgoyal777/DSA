#include <iostream>
using namespace std;

int main()
{
    int array[] = {2,3,4,5,5,6,7,9,10};
    int target;
    int start = 0;
    int last = sizeof(array)/sizeof(array[0]) - 1;
    cout << "Enter target value to find in the array: ";
    cin >> target;

    while(last >= start)
    {
        int mid = start +(last - start) / 2;
        if(array[mid]==target)
        {
            cout << "Element found at index " << mid << endl;
            break;
        }
        else if(array[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            last = mid - 1; //if (array[mid] > target)
        }
    }
    if(last < start)
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
