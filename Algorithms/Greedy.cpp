// A greedy algorithm builds up a solution piece by piece, always choosing the next piece that offers the most immediate benefit(local optimum), with the hope of finding the global optimum. It doesn't reconsider its choices, which means it may or may not lead to the best solution.

// A Greedy Algorithm is like trying to collect the most money in a game by grabbing the highest available value at each step without looking back.The idea is to make the best choice at each step, hoping it leads to the overall best solution.

// Example :
// Imagine you have coins of different denominations and you want to make a certain amount using the fewest number of coins.
// Suppose you have coins of values 1, 3, and4, and you want to make a total of 6.

// Greedy Approach :
// You’ll start by choosing the largest coin value(4), then choose the next largest(1), and then another '1'.
// You’ve used 3 coins : {4, 1, 1}.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the minimum number of coins needed to make a given amount
int minCoins(vector<int> &coins, int amount)
{
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order
    int count = 0;

    for (int i = 0; i < coins.size(); i++)
    {
        while (amount >= coins[i])
        {                       // While you can still use this coin
            amount -= coins[i]; // Subtract the coin value from the amount
            count++;            // Increment the coin count
        }
    }

    return count;
}

int main()
{
    vector<int> coins = {1, 3, 4}; // Available coin denominations
    int amount;

    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);

    cout << "Minimum coins needed: " << result << endl;

    return 0;
}
