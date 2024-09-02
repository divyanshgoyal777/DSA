#include <iostream>
using namespace std;

int main()
{
    int array[4][4]= {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int sum = 0;
    int n = 4;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(i==j)
            {
                sum += array[i][j];
            }
            if(i+j==n-1)
            {
                sum+=array[i][j];
            }
        }
    }
    cout <<sum;
    return 0;
}
