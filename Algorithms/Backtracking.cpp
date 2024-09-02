// Backtracking is a problem-solving algorithmic technique that involves finding a solution incrementally by trying different options and undoing them if they lead to a dead end. It is commonly used in situations where you need to explore multiple possibilities to solve a problem, like searching for a path in a maze or solving puzzles like Sudoku. When a dead end is reached, the algorithm backtracks to the previous decision point and explores a different path until a solution is found or all possibilities have been exhausted.

// Types of Backtracking Problems - 
    // Decision Problems: Here, we search for a feasible solution.
    // Optimization Problems: For this type, we search for the best solution.
    // Enumeration Problems: We find set of all possible feasible solutions to the problems of this type.

// Must Do Backtracking Problems -
    // N-Queen Problem
    // Solve Sudoku
    // M-coloring problem
    // Rat in a Maze
    // The Knight’s tour problem
    // Permutation of given String

// SUBSETS OF ARRAY

// #include <iostream>
// #include <vector>
// using namespace std;

// void subset(vector<int> &array, vector<int> &current, int index)
// {
//     if (index == array.size())
//     {
//         if (current.empty())
//         {
//             cout << "NULL";
//         }
//         else
//         {
//             for (int i = 0; i < current.size(); i++)
//             {
//                 cout << current[i];
//             }
//             cout << endl;
//             return;
//         }
//     }
//     current.push_back(array[index]);
//     subset(array, current, index + 1);
//     current.pop_back();
//     subset(array, current, index + 1);
// }

// int main()
// {
//     vector<int> array;
//     array = {1, 2, 3, 4, 5, 6};
//     vector<int> current;
//     subset(array, current, 0);
//     return 0;
// }

// OPTIMIZE WAY OF SUBSETS OF ARRAY

#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<int> &A, vector<vector<int>> &res,
                vector<int> &subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++)
    {
        subset.push_back(A[i]);
        calcSubset(A, res, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &A)
{
    vector<int> subset;
    vector<vector<int>> res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<vector<int>> res = subsets(array);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}

//SUBSETS OF STRING

// #include <iostream>
// #include <string>
// using namespace std;

// void subset(string str, string current, int index)
// {
//     if (index == str.length())
//     {
//         if (current.empty())
//         {
//             cout << "NULL"; 
//         }
//         cout << current << endl;
//         return;
//     }

//     subset(str, current + str[index], index + 1);
//     subset(str, current, index + 1);
// }

// int main()
// {
//     string str = "abc";
//     string current = "";
//     subset(str, current, 0);
//     return 0;
// }