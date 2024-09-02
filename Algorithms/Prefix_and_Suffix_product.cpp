// PREFIX PRODUCT

// The prefix product of an array is an array where each element at index i contains the product of all elements of the original array from index 0 to i.

// Example :   Original Array : [ 1, 2, 3, 4, 5 ] 
            // Prefix Product Array : [ 1, 2, 6, 24, 120 ]

// Formula : prefix_product[i] = arr[0] × arr[1] × ⋯ × arr[i] 

//SUFFIX PRODUCT

// The suffix product of an array is an array where each element at index i contains the product of all elements of the original array from index i to the last index.

// Example :   Original Array : [ 1, 2, 3, 4, 5 ] 
            // Suffix Product Array : [ 120, 120, 60, 20, 5 ]

// Formula : suffix_product[i] = arr[i] × arr[i + 1] × ⋯ × arr[n − 1]

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    vector<int> prefix_product(n, 1);
    vector<int> suffix_product(n, 1);

    prefix_product[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_product[i] = prefix_product[i - 1] * arr[i];
    }

    suffix_product[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_product[i] = suffix_product[i + 1] * arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Prefix Product Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix_product[i] << " ";
    }
    cout << endl;

    cout << "Suffix Product Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << suffix_product[i] << " ";
    }
    cout << endl;

    return 0;
}
