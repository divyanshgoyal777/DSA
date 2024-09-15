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
        root->right->right->right = new TreeNode(11);
        root->left->left->left = new TreeNode(8);
        root->left->left->right = new TreeNode(10);
        root->left->left->left->left = new TreeNode(9);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (Identical(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool Identical(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        if (root->val != subRoot->val)
        {
            return false;
        }
        cout << "Comparing Node " << root->val << " with Subtree Node " << subRoot->val << endl;
        return Identical(root->left, subRoot->left) && Identical(root->right, subRoot->right);
    }
};

int main()
{
    BinaryTree tree;
    BinaryTree::TreeNode *subTree = new BinaryTree::TreeNode(3);
    subTree->left = new BinaryTree::TreeNode(6);
    subTree->right = new BinaryTree::TreeNode(7);

    if (tree.isSubtree(tree.root, subTree))
    {
        cout << "Subtree is part of main tree." << endl;
    }
    else
    {
        cout << "Subtree is not part of main tree." << endl;
    }
    return 0;
}
