#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(10);
    q.push(12);
    cout << "Size before popping: " << q.size() << endl;
    cout << "Top Element before popping: " << q.top() << endl;
    q.pop();
    cout << (q.empty() ? "Queue is Empty" : "Queue is Not Empty") << endl;
    cout << "Size after popping: " << q.size() << endl;
    if (!q.empty())
    {
        cout << "Top Element after popping: " << q.top() << endl;
    }

    return 0;
}
