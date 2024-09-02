#include <iostream>
#include <vector>
using namespace std;

int numTeams(vector<int> &rating)
{
    int count = 0;
    int n = rating.size() - 1;
    if (n < 2)
        return 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (rating[i] < rating[j] && rating[j] < rating[k] || rating[i] > rating[j] && rating[j] > rating[k])
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    vector<int> rating = {1, 2, 3};
    int count = numTeams(rating);
    cout << count;

    return 0;
}