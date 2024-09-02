#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> ll;
    ll.push_front(1);
    ll.push_back(33);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(4);
    ll.push_front(5);
    cout << "First element is " << ll.front() << endl;
    cout << "Back element is " << ll.back() << endl;
    while(!ll.empty()){
        cout << ll.front() << " ";
        ll.pop_front();
    }

    return 0;
}