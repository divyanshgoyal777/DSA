#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> &array, vector<int> &current, int index)
{
    if (index == array.size())
    {
        if (current.empty())
        {
            cout << "NULL";
        }
        else
        {
            for (int i = 0; i < current.size(); i++)
            {
                cout << current[i];
            }
            cout << endl;
            return;
        }
    }
    current.push_back(array[index]);
    subset(array, current, index + 1);
    current.pop_back();
    subset(array, current, index + 1);
}

int main()
{
    vector<int> array;
    array = {1, 2, 3, 4, 5, 6};
    vector<int> current;
    subset(array, current, 0);
    return 0;
}