#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        Node *children[26];
        int prefixCount;
        bool eow;

        Node()
        {
            prefixCount = 0;
            eow = false;
            for (int k = 0; k < 26; k++)
            {
                children[k] = nullptr;
            }
        }
    };

private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(const string &word)
    {
        Node *temp = root;
        for (char letter : word)
        {
            int num = letter - 'a';
            if (temp->children[num] == nullptr)
            {
                temp->children[num] = new Node();
            }
            temp = temp->children[num];
            temp->prefixCount++;
        }
        temp->eow = true;
    }

    int sumPrefixScores(const string &str)
    {
        Node *temp = root;
        int score = 0;

        for (char letter : str)
        {
            int num = letter - 'a';
            if (temp->children[num] == nullptr)
            {
                break;
            }
            temp = temp->children[num];
            score += temp->prefixCount;
        }
        return score;
    }
};

int main()
{
    Trie trie;
    vector<int> result;
    vector<string> words = {"abc", "ab", "bc", "b"};

    for (const string &word : words)
    {
        trie.insert(word);
    }

    for (const string &word : words)
    {
        result.push_back(trie.sumPrefixScores(word));
    }

    for (int score : result)
    {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
