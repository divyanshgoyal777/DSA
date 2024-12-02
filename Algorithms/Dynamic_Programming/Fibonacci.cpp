#include <bits/stdc++.h>
using namespace std;

int fib(int n, int arr[])
{
    if (n <= 1)
    {
        return n;
    }
    int fib1 = arr[n - 1] == 0 ? fib(n - 1, arr) : arr[n - 1];
    int fib2 = arr[n - 2];
    int ans = fib1 + fib2;
    arr[n] = ans;
    return ans;
}

int main()
{
    int n = 10;
    int arr[n + 1] = {0};
    arr[0] = 0;
    arr[1] = 1;
    int ans = fib(n, arr);
    cout << ans;
    return 0;
}