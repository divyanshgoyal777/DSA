#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push(s[i]);
        }
        else
        {
            if (stack.empty())
                return false;
            char top = stack.top();
            stack.pop();
            if ((s[i] == ')' && top != '(') || (s[i] == '[' && top != ']') || (s[i] == '{' && top != '}'))
                return false;
        }
    }
    return stack.empty();
}

int main()
{
    string a = "({[([([{}])])]})";
    isValidParenthesis(a) ? cout << "TRUE - It is valid parenthesis" << endl : cout << "FALSE - It is invalid parenthesis" << endl;

    return 0;
}