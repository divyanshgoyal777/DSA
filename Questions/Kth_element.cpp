#include <iostream>
#include <queue>
using namespace std;

void nthMin(priority_queue<int, vector<int>, greater<int>> &g, int n)
{
    int count = 1;
    while (count < n)
    {
        g.pop();
        count++;
    }
    cout << "The " << n << "th minimum element: " << g.top() << endl;
}

void nthMax(priority_queue<int> &g, int n)
{
    int count = 1;
    while (count < n)
    {
        g.pop();
        count++;
    }
    cout << "The " << n << "th maximum element: " << g.top() << endl;
}

int main()
{
    int arr[7] = {1, 5, 3, 10, 15, 11, 12};
    priority_queue<int, vector<int>, greater<int>> minq(arr, arr + 7);
    nthMin(minq, 3);
    priority_queue<int> maxq(arr, arr + 7);
    nthMax(maxq, 4); 
    return 0;
}
