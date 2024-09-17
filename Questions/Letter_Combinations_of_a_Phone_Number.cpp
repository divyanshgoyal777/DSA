#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

void backtrack(string &digits, string &current, int index, unordered_map<char, string> &digitMap, vector<string> &result)
{
    if (index == digits.size())
    {
        result.push_back(current);
        return;
    }
    char digit = digits[index];
    string letters = digitMap[digit];
    for (char letter : letters)
    {
        current.push_back(letter);
        backtrack(digits, current, index + 1, digitMap, result);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
    {
        return {};
    }
    unordered_map<char, string> digitMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    vector<string> result;
    string current = "";
    backtrack(digits, current, 0, digitMap, result);
    return result;
}

int main()
{
    string digits;
    cout << "Enter digits: ";
    cin >> digits;
    vector<string> combinations = letterCombinations(digits);
    cout << "Possible combinations are: " << endl;
    for (const string &combination : combinations)
    {
        cout << combination << endl;
    }
    return 0;
}