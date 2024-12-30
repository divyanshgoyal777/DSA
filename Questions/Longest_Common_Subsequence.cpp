#include <bits/stdc++.h>
using namespace std;

int subsequence(string str1, string str2, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (str1[m - 1] == str2[n - 1])
    {
        return subsequence(str1, str2, m - 1, n - 1) + 1;
    }
    else
    {
        return max(subsequence(str1, str2, m - 1, n), subsequence(str1, str2, m, n - 1));
    }
}

int main()
{
    string str1 = "abcdefg";
    string str2 = "abcde";
    int m = str1.length();
    int n = str2.length();
    int result = subsequence(str1, str2, m, n);
    cout << result;

    return 0;
}