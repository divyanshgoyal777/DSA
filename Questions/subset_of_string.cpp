#include <iostream>
#include <string>
using namespace std;

void subset(string str, string current, int index)
{
    if (index == str.length())
    {
        if (current.empty())
        {
            cout << "NULL";
        }
        cout << current << endl;
        return;
    }

    subset(str, current + str[index], index + 1);
    subset(str, current, index + 1);
}

int main()
{
    string str = "abc";
    string current = "";
    subset(str, current, 0);
    return 0;
}