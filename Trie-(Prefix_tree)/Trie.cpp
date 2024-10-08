#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        Node *children[26];
        bool eow;
        Node()
        {
            eow = false;
            for (int k = 0; k < 26; k++)
            {
                children[k] = nullptr;
            }
        }
    };

private:
    Node *root = new Node();

public:
    void insert(string word)
    {
        Node *temp = root;
        for (char letter : word)
        {
            letter = tolower(letter);
            int idx = letter - 'a';
            if (temp->children[idx] == nullptr)
            {
                temp->children[idx] = new Node();
            }
            temp = temp->children[idx];
        }
        temp->eow = true;
    }

    bool searchLetter(char letter)
    {
        letter = tolower(letter);
        int idx = letter - 'a';
        return searchInTrie(root, idx);
    }

private:
    bool searchInTrie(Node *node, int idx)
    {
        if (node->children[idx] != nullptr)
        {
            return true;
        }
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                if (searchInTrie(node->children[i], idx))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Trie trie;
    string word = "Hello";
    trie.insert(word);
    char letter = 'o';
    if (trie.searchLetter(letter))
    {
        cout << "Letter found!" << endl;
    }
    else
    {
        cout << "Letter not found!" << endl;
    }
    letter = 'a';
    if (trie.searchLetter(letter))
    {
        cout << "Letter found!" << endl;
    }
    else
    {
        cout << "Letter not found!" << endl;
    }

    return 0;
}
