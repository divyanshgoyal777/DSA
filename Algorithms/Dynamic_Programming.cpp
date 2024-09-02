// Dynamic Programming is a method used in mathematics and computer science to solve complex problems by breaking them down into simpler subproblems. By solving each subproblem only once and storing the results, it avoids redundant computations, leading to more efficient solutions for a wide range of problems.

// Dynamic Programming is like solving a puzzle by breaking it into smaller pieces, solving each piece, and then combining the solutions.Imagine you’re climbing a staircase.If you want to reach the top, you could take one step at a time, or sometimes two steps.If you know the best way to get to the previous steps, you can easily figure out the best way to get to the next one.

// Example : Let's use the example of finding the nth Fibonacci number:

// The Fibonacci sequence is 1,1,2,3,5,8,13,... where each number is the sum of the two preceding ones.
    
// Traditional Approach(Recursive) :
// You might write a function that calls itself to calculate the Fibonacci number.But this approach recalculates the same values multiple times, which is inefficient.

// DP Approach(Memoization) :
// Instead of recalculating, you store the results of each Fibonacci calculation in an array.When you need to calculate a number you’ve already computed, you just look it up.

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Fibonacci number using DP (Memoization)
int fibonacci(int n, vector<int> &memo)
{
    if (n <= 1)
        return n; // Base case: fib(0) = 0, fib(1) = 1
    if (memo[n] != -1)
        return memo[n];                                        // If already computed, return it
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo); // Store result
    return memo[n];
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    int result = fibonacci(n, memo);

    cout << "Fibonacci of " << n << " is " << result << endl;

    return 0;
}
