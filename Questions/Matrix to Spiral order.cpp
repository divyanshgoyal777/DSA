// #include <iostream>
// using namespace std;

// int main()
// {
    // int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // int sr = 0;
    // int sc = 0;
    // int er = (sizeof(matrix) / sizeof(matrix[0])) - 1;
    // int ec = 3;
    // while (sr <= er && sc <= ec)
    // {
    //     for (int i = sc; i <= ec; i++) // top
    //     {
    //         cout << matrix[sr][i] << "  ";
    //     }
    //     for (int i = sr + 1; i < er; i++) // right
    //     {
    //         cout << matrix[i][ec] << "  ";
    //     }
    //     for (int i = ec; i >= sc; i--) // bottom
    //     {
    //         if (sr == er)
    //             break;
    //         cout << matrix[er][i] << "  ";
    //     }
    //     for (int i = er - 1; i > sr; i--) // left
    //     {
    //         if (sc == ec)
    //             break;
    //         cout << matrix[i][sc] << "  ";
    //     }
    //     sr++;
    //     sc++;
    //     er--;
    //     ec--;
    // }
//     return 0;
// }


#include <iostream>
using namespace std;

int main()
{
    int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int sr = 0;
    int sc = 0;
    int er = (sizeof(matrix) / sizeof(matrix[0])) - 1;
    int ec = 3;
    while (sr <= er && sc <= ec)
    {
        for (int i = sc; i <= ec; i++) // top
        {
            cout << matrix[sr][i] << "  ";
        }
        for (int i = sr + 1; i < er; i++) // right
        {
            cout << matrix[i][ec] << "  ";
        }
        for (int i = ec; i >= sc; i--) // bottom
        {
            if (sr == er)
                break;
            cout << matrix[er][i] << "  ";
        }
        for (int i = er - 1; i > sr; i--) // left
        {
            if (sc == ec)
                break;
            cout << matrix[i][sc] << "  ";
        }
        sr++;
        sc++;
        er--;
        ec--;
    }
    return 0;
}
