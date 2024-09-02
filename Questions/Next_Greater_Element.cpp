#include <iostream>
#include <stack>
using namespace std;

void NxtGtrElement(int arr[], int size)
{
    stack<int> stack;
    int gtr[size];
    for (int i = size - 1; i >= 0; i--) 
    {
        while (!stack.empty() && stack.top() <= arr[i])
        {
            stack.pop();
        }
        if (stack.empty())
        {
            gtr[i] = -1;
        }
        else
        {
            gtr[i] = stack.top();
        }
        stack.push(arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        cout << gtr[i] << " ";
    }
}

int main()
{
    int array[] = {6, 0, 1, 8, 5};
    NxtGtrElement(array, 5);

    return 0;
}