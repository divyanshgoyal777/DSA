#include <iostream>
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
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        root->left->left->left = new TreeNode(8);
        root->left->left->right = new TreeNode(10);
        root->left->left->left->left = new TreeNode(9);
    }

    int countNodes(TreeNode *root)
    {
        int count = 0;
        if (root == nullptr)
        {
            return 0;
        }
        // int left = countNodes(root->left);
        // int right = countNodes(root->right);
        // count = left + right + 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
        // return count;
    };
};

int main()
{
    BinaryTree tree;
    cout << "Nodes in the tree: " << tree.countNodes(tree.root) << endl;

    return 0;
}
