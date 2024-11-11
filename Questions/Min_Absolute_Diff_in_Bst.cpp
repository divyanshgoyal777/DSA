#include <iostream>
#include <vector>
using namespace std;

class BinarySearchTree
{
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int value)
        {
            data = value;
            left = right = nullptr;
        }
    };

    Node *root;

    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void inOrderTraversal(Node *node, vector<int> &v)
    {   
        if (node != nullptr)
        {
            inOrderTraversal(node->left, v);
            cout << node->data << " ";
            v.push_back(node->data);
            inOrderTraversal(node->right, v);
        }
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    vector<int> inOrder(vector<int> &v)
    {
        inOrderTraversal(root, v);
        cout << endl;
        return v;
    }
};

int main()
{
    BinarySearchTree bst;
    vector<int> val;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.inOrder(val);
    int diff;
    int minDiff = 99999999;
    for (int i = 0; i < val.size() - 1; i++){
        diff = val[i + 1] - val[i];
        minDiff = min(diff, minDiff);
    }
    cout << minDiff;
    return 0;
}
