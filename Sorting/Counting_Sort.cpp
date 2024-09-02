#include <iostream>
using namespace std;

void countSort(int num[], int size)
{
    int max = num[0];
    for (int i = 1; i < size; i++)
    {
        if (max < num[i])
        {
            max = num[i];
        }
    }
    int array[max + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        array[num[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        while(array[i] != 0){
            cout << i << " ";
            array[i]--;
        }
    }
}

int main()
{
    int arr[] = {23, 14, 21, 10, 53, 25};
    countSort(arr, 6);
};