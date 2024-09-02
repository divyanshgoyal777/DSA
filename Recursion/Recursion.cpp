#include <iostream>
using namespace std;

// int factorial(int k) // factorial
// {
//     if (k == 1)
//     {
//         return 1;
//     }
//     return k * factorial(k - 1);
// }

// void n(int k) //Print numbers descending
// {
//     if(k < 1){
//         return;
//     }
//     cout << k << " ";
//     n(k - 1);
// }

// void n(int a, int k)   // Print numbers ascending
// {
//     if (a > k)
//     {
//         return;
//     }
//     cout << a << " ";
//     n(a+1, k);
// }

// int fibonacci(int k)
// {
//     if (k == 0 || k == 1)
//     {
//         return k;
//     }
//     return fibonacci(k-1) + fibonacci(k-2);
// }

// int sum(int k)  // upto sum of n natural numbers
// {
//     if(k == 0 || k == 1){
//         return k;
//     }
//     return k + sum(k-1);
// }

// bool isSorted(int k[], int size) // check given array sorted or not
// {
//     if (size <= 1)
//     {
//         return true;
//     }
//     if (k[0] > k[1])
//     {
//         return false;
//     }
//     return isSorted(k + 1, size - 1); //passing subarray
// }

// bool isSorted(int k[], int i, int size)
// {
//     if (i == size)
//     {
//         return true;
//     }
//     if (k[i - 1] > k[i])
//     {
//         return false;
//     }
//     return isSorted(k, i + 1, size);
// }

int pow(int k, int p) // power function
{
    // if (p == 0)
    // {
    //     return 1;
    // }

    // return k * pow(k, p - 1);

    if (p == 0)
    {
        return 1;
    }
    int ans = pow(k, p / 2) * pow(k, p / 2);
    if (p % 2 != 0)
    {
        ans = k * ans;
    }
    return ans;
}

int main()
{
    int result = pow(3, 3);
    cout << result;
    return 0;
}