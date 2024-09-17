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
        root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(7);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(25);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
            return right;

        if (right == nullptr)
            return left;

        return root;
    }

    void printNode(TreeNode *node)
    {
        if (node)
        {
            cout << "Node value: " << node->val << endl;
        }
        else
        {
            cout << "Node is nullptr" << endl;
        }
    }
};

int main()
{
    BinaryTree tree;
    BinaryTree::TreeNode *p = tree.root->left->left;
    BinaryTree::TreeNode *q = tree.root->right->right;
    BinaryTree::TreeNode *lca = tree.lowestCommonAncestor(tree.root, p, q);
    tree.printNode(lca);
    return 0;
}
