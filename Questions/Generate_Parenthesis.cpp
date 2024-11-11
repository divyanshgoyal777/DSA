#include <iostream>
#include <vector>
using namespace std;

void generateBrackets(string current, int open, int close, int n)
{
    if (current.size() == 2 * n)
    {
        cout << current << endl;
        return;
    }
    if (open < n)
    {
        generateBrackets(current + "(", open + 1, close, n);
    }
    if (close < open)
    {
        generateBrackets(current + ")", open, close + 1, n);
    }
}

int main()
{
    int n;
    cout << "Enter the number of pairs of brackets: ";
    cin >> n;
    generateBrackets("", 0, 0, n);

    return 0;
}
