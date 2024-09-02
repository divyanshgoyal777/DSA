#include <iostream>
#include <queue>
using namespace std;

int main(){
    
    queue<int> queue;
    queue.push(32);
    queue.push(31);
    queue.push(13);
    queue.push(34);
    queue.push(52);

    queue.pop();
    cout << "Front element is " << queue.front() << endl;
    cout << "Back element is " << queue.back() << endl;
    cout << "The size of queue is " << queue.size() << endl;
    
    while(!queue.empty()){
      cout << queue.front() << " ";
      queue.pop();
    }
    
    cout << endl;
    
    cout << "The size of queue is " << queue.size() << endl;
    
    return 0;
}