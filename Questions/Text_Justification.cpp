#include <iostream>
#include <vector>
#include <string>
using namespace std;

string justifyLine(const vector<string> &words, int numOfLetters, int maxWidth, bool isLastLine)
{
    string line;
    int spaces = maxWidth - numOfLetters;
    int numOfGaps = words.size() - 1;
    if (isLastLine || numOfGaps == 0)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            if (i > 0)
                line += " ";
            line += words[i];
        }
        line += string(maxWidth - line.size(), ' ');
    }
    else
    {
        int spaceBetweenWords = spaces / numOfGaps;
        int extraSpaces = spaces % numOfGaps;
        for (int i = 0; i < words.size(); ++i)
        {
            if (i > 0)
            {
                int currentSpaces =
                    spaceBetweenWords + (i <= extraSpaces ? 1 : 0);
                line += string(currentSpaces, ' ');
            }
            line += words[i];
        }
    }
    return line;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    vector<string> line;
    int numOfLetters = 0;
    for (const string &word : words)
    {
        if (numOfLetters + word.size() + line.size() > maxWidth)
        {
            result.push_back(
                justifyLine(line, numOfLetters, maxWidth, false));
            line.clear();
            numOfLetters = 0;
        }
        line.push_back(word);
        numOfLetters += word.size();
    }
    result.push_back(justifyLine(line, numOfLetters, maxWidth, true));
    return result;
}

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 11;
    vector<string> result = fullJustify(words, maxWidth);
    for (string res : result)
    {
        cout << res << endl;
    }
    return 0;
}