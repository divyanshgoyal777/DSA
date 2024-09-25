#include <iostream>
#include <queue>
using namespace std;

void min(priority_queue<int, vector<int>, greater<int>> g, int n)
{
    int count = 1;
    while (count != n)
    {
        g.pop();
        count++;
    }
    cout << g.top();
    cout << endl;
}

void max(priority_queue<int> g, int n)
{
    int count = 1;
    while (count != n)
    {
        g.pop();
        count++;
    }
    cout << g.top();
    cout << endl;
}

int main()
{
    int arr[7] = {1, 5, 3, 10, 15, 11, 12};
    priority_queue<int, vector<int>, greater<int>> minq(arr, arr + 7);
    min(minq, 3);

    priority_queue<int> maxq(arr, arr + 7);
    max(maxq, 4);

    return 0;
}