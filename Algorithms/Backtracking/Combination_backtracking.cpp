#include <iostream>
#include <vector>
using namespace std;

void combination(vector<int> &array, vector<int> &current, int index, int n)
{
    if (current.size() == n)
    {
        for (int i = 0; i < current.size(); i++)
        {
            cout << current[i];
        }
        cout << endl;
        return;
    }

    if (index >= array.size())
    {
        return;
    }

    current.push_back(array[index]);
    combination(array, current, index + 1, n);
    current.pop_back();
    combination(array, current, index + 1, n);
}

int main()
{
    vector<int> array;
    array = {1, 2, 3, 4, 5};
    vector<int> current;
    int n = 3;
    combination(array, current, 0, n);

    return 0;
}