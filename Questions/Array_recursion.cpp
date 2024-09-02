#include <iostream>
#include <vector>
using namespace std;

void arrayRecursion(vector<int> &arr, int start, int size, int i)
{
    if (start > size)
    {
        return;
    }
    arr[start] = i;
    arrayRecursion(arr, start + 1, size, i + 1);
}

int main()
{
    vector<int> array(10);
    int start = 0;
    int size = array.size() - 1;
    int i = 1;
    arrayRecursion(array, start, size, i);
    for (int i = 0; i <= size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// int arrayRecursion(vector<int> &arr, int start, int size, int i)
// {
//     if (start > size)
//     {
//         return -1;
//     }
//     arr[start] = i;
//     return arrayRecursion(arr, start + 1, size, i + 1);
// }

// int main()
// {
//     vector<int> array(10);
//     int start = 0;
//     int size = array.size() - 1;
//     int i = 1;
//     arrayRecursion(array, start, size, i);
//     for (int i = 0; i <= size; i++)
//     {
//         cout << array[i] << " ";
//     }

//     return 0;
// }