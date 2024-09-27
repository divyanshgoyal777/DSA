#include <iostream>
#include <vector>
using namespace std;

void add(vector<int> &v, int key)
{
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        if (v[mid] < key)
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    v.insert(v.begin() + i, key);
}

int main()
{
    vector<int> v = {1, 2, 4, 5, 6, 7, 8};
    int key = 3;
    add(v, key);
    for (int value : v)
    {
        cout << value << " ";
    }
    return 0;
}