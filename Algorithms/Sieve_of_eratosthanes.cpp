#include <bits/stdc++.h>
using namespace std;

void prime(bool arr[], int n)
{
    int count = 0;
    fill(arr, arr + n + 1, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
        {
            count++;
            int j = i * i;
            while (j <= n)
            {
                arr[j] = false;
                j += i;
            }
        }
    }
    cout << "Number of primes: " << count << endl;
}

int main()
{
    int n = 10;
    bool arr[n + 1];
    prime(arr, n);
    return 0;
}
