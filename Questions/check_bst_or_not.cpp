#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
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

public:
    BinarySearchTree()
    {
        root = new Node(25);
        root->left = new Node(5);
        root->left->left = new Node(3);
        root->left->right = new Node(7);
        root->right = new Node(30);
        root->right->left = new Node(28);
        root->right->right = new Node(35);
    }

    bool isBst(Node *node)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (node->left != nullptr && node->left->data >= node->data)
        {
            return false;
        }

        if (node->right != nullptr && node->right->data <= node->data)
        {
            return false;
        }

        return isBst(node->left) && isBst(node->right);
    }

    bool isBst()
    {
        return isBst(root);
    }
};

int main()
{
    BinarySearchTree bst;
    if (bst.isBst())
    {
        cout << "Tree is BST" << endl;
    }
    else
    {
        cout << "Tree is not BST" << endl;
    }

    return 0;
}
