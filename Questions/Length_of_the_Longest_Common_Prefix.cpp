#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        Node *children[10];
        bool eow;

        Node()
        {
            eow = false;
            for (int k = 0; k < 10; k++)
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

    void insert(string arr1)
    {
        Node *temp = root;
        for (char letter : arr1)
        {
            int num = letter - '0';
            if (temp->children[num] == nullptr)
            {
                temp->children[num] = new Node();
            }
            temp = temp->children[num];
        }
        temp->eow = true;
    }

    int longestCommonPrefixLength(const string &str)
    {
        Node *temp = root;
        int length = 0;

        for (char letter : str)
        {
            int num = letter - '0';
            if (temp->children[num] == nullptr)
            {
                break;
            }
            temp = temp->children[num];
            length++;
        }

        return length;
    }
};

int main()
{
    Trie trie;
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};

    for (int i = 0; i < arr1.size(); i++)
    {
        trie.insert(to_string(arr1[i]));
    }

    int maxLength = 0;

    for (int i = 0; i < arr2.size(); i++)
    {
        int length = trie.longestCommonPrefixLength(to_string(arr2[i]));
        maxLength = max(maxLength, length);
    }

    cout << "Length of the longest common prefix: " << maxLength << endl;

    return 0;
}
