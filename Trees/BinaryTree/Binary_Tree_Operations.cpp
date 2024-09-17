#include <iostream>
#include <queue>
using namespace std;

class BinaryTree
{
public:
    class TreeNode
    {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data)
        {
            val = data;
            left = nullptr;
            right = nullptr;
        }
    };

    TreeNode *root;

    BinaryTree()
    {
        root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(7);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(25);
    }
};

int main()
{
    BinaryTree tree;


    return 0;
}
