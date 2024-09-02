#include <iostream>
#include <string>
#include <stack>
using namespace std;

void UnixStyle(string s)
{
    stack<string> stack;
    string result, dir;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '/')
        {
            if (!dir.empty())
            {
                if (dir == "..")
                {
                    if (!stack.empty())
                        stack.pop(); 
                }
                else if (dir != ".")
                {
                    stack.push(dir);
                }
                dir.clear();
            }
        }
        else
        {
            dir += s[i];
        }
    }

    if (!dir.empty())
    {
        if (dir == "..")
        {
            if (!stack.empty())
                stack.pop();
        }
        else if (dir != ".")
        {
            stack.push(dir);
        }
    }

    while (!stack.empty())
    {
        result = "/" + stack.top() + result;
        stack.pop();
    }

    if (result.empty())
    {
        result = "/";
    }

    cout << result << endl;
}

int main()
{
    string s = "/home/user/Documents/../Pictures/";
    UnixStyle(s);
    
    return 0;
}
