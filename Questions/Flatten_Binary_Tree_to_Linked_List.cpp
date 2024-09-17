#include <iostream>
#include <list>
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
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right = new TreeNode(5);
        root->right->right = new TreeNode(6);
    }

    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        TreeNode *current = root;

        while (current != nullptr)
        {
            if (current->left != nullptr)
            {
                TreeNode *rightMost = current->left;
                while (rightMost->right != nullptr)
                {
                    rightMost = rightMost->right;
                }
                rightMost->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }

    void printFlattenedTree(TreeNode *root)
    {
        TreeNode *current = root;
        while (current != nullptr)
        {
            cout << current->val;
            if (current->right != nullptr)
            {
                cout << " -> ";
            }
            current = current->right;
        }
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    tree.flatten(tree.root);
    tree.printFlattenedTree(tree.root);
    return 0;
}
