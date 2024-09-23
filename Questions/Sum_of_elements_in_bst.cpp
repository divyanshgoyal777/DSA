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
        root->right = new Node(20);
        root->right->left = new Node(25);
        root->right->right = new Node(35);
    }

    int s = 0;
    int sum(Node *root)
    {
        if (root == nullptr)
        {
            return s;
        }
        sum(root->left);
        s = s + root->data;
        sum(root->right);
    }
};

int main()
{
    BinarySearchTree bst;
    cout << "Sum of all elements of a tree " << bst.sum(bst.root);
    return 0;
}