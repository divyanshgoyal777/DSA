#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void permutation(vector<int> &array, int index)
{
    if (index == array.size())
    {
        for (int num : array)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = index; i < array.size(); i++)
    {
        swap(array[index], array[i]);  // Swap to fix one element
        permutation(array, index + 1); // Recursively call for the next index
        swap(array[index], array[i]);  // Swap back to restore original order
    }
}


int main()
{
    vector<int> array;
    array = {1, 2, 3, 4, 5};
    vector<int> current;
    permutation(array, 0);
    return 0;
}