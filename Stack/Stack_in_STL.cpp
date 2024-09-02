#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> stack;
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(5);
    stack.pop();

    while(!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
    
    stack.push(3);
    
    if(stack.empty()){
      cout << "Stack is empty" << endl;
    }
    else{
      cout << "Stack is not empty" << endl;
    }
    
    int top = stack.top();
    cout << top << " is on the top" << endl;
    return 0;
}