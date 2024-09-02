// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;


// int maxRectangleInHistogram(const vector<int> &heights)
// {
    // stack<int> stack;
    // int max_area = 0;
    // int index = 0;
    // int n = heights.size();

    // while (index < n)
    // {
    //     if (stack.empty() || heights[index] >= heights[stack.top()])
    //     {
    //         stack.push(index++);
    //     }
    //     else
    //     {
    //         int top_of_stack = stack.top();
    //         stack.pop();
    //         int area = heights[top_of_stack] * (stack.empty() ? index : index - stack.top() - 1);
    //         max_area = max(max_area, area);
    //     }
    // }

    // while (!stack.empty())
    // {
    //     int top_of_stack = stack.top();
    //     stack.pop();
    //     int area = heights[top_of_stack] * (stack.empty() ? index : index - stack.top() - 1);
    //     max_area = max(max_area, area);
    // }

    // return max_area;
// }

// int main()
// {
//     vector<int> histogram = {2, 1, 5, 6, 2, 3};
//     int max_area = maxRectangleInHistogram(histogram);
//     cout << "Maximum Rectangle Area in Histogram: " << max_area << endl;
//     return 0;
// }


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int rectangle(vector<int>& heights ){
    int n = heights.size();
    stack<int> st;
    int max_area = 0;
    int leftSmall[n], rightSmall[n];
    for(int i = 0; i < n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()){
            leftSmall[i] = 0;
        }
        else{
            leftSmall[i] = st.top() + 1;
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()){
            rightSmall[i] = n - 1;
        }
        else{
            rightSmall[i] = st.top() - 1;
        }
        st.push(i);
    }
    for(int i = 0; i < n; i++){
        max_area = max(max_area, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }
    return max_area;
}

int main(){
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int max_area = rectangle(heights);
    cout << "Maximum Rectangle Area in Histogram: " << max_area << endl;
    return 0;
}