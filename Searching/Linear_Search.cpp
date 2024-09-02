#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return i; 
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {3, 5, 7, 9, 11, 13, 15};
    int target = 9;

    int result = linearSearch(arr, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
