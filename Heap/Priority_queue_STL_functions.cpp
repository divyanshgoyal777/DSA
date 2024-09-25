#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(10);
    q.push(12);
    q.pop();
    q.empty() ? cout << "Empty" << endl : cout << "Not Empty" << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Top Element: " << q.top() << endl;
    return 0;
}