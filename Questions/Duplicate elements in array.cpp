K#include <iostream>
using namespace std;

int duplicate(int array[])
{
    for(int i = 0; i <= sizeof(array); i++)
    {
        for(int j = i+1; j<= sizeof(array); j++)
        {
            if(array[i] == array[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int array[] = {1,2,3,4};
    if(duplicate(array))
    {
        cout << "Duplicate" << endl;
    }
    else
    {
        cout << "No Duplicate found" << endl;

    }
    return 0;
}
