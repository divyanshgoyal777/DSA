#include <iostream>
using namespace std;

int main()
{
    int array[3][3]= {{1,2,3}, {4,5,6}, {7,8,9}};
    int sum = 0;
    int n = 3;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i==j)
            {
                sum += array[i][j];
            }
            else if(i+j==n-1)
            {
                sum+=array[i][j];
            }
        }
    }
    cout <<sum;
    return 0;
}
