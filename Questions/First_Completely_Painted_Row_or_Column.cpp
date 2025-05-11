#include <bits/stdc++.h>
using namespace std;

int checkRowCol(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    for (int i = 0; i < row; i++)
    {
        bool rowComplete = true;
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] != -1)
            {
                rowComplete = false;
                break;
            }
        }
        if (rowComplete)
        {
            return true;
        }
    }
    for (int j = 0; j < col; j++)
    {
        bool colComplete = true;
        for (int i = 0; i < row; i++)
        {
            if (mat[i][j] != -1)
            {
                colComplete = false;
                break;
            }
        }
        if (colComplete)
        {
            return true;
        }
    }

    return false;
}

int paint(vector<vector<int>> &mat, int idx)
{
    int row = mat.size();
    int col = mat[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == idx)
            {
                mat[i][j] = -1;
                return checkRowCol(mat);
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};

    for (int i = 0; i < arr.size(); i++)
    {
        if (paint(mat, arr[i]))
        {
            cout << arr[i];
        }
    }

    return 0;
}