#include <iostream>
using namespace std;

int tiles(int n)
{
    // Base cases
    if (n == 0 || n == 1)
    {
        return 1;
    }

    // Recursive calls
    int vertical = tiles(n - 1);
    int horizontal = tiles(n - 2);

    // Total ways
    return vertical + horizontal;
}

int main()
{
    int n = 4;
    cout << tiles(n) << endl;
    return 0;
}
