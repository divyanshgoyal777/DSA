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

    // In-order traversal (left, root, right)
    void inOrderTraversal(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        inOrderTraversal(node->left);
        cout << node->val << " ";
        inOrderTraversal(node->right);
    }

    // Pre-order traversal (root, left, right)
    void preOrderTraversal(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->val << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Post-order traversal (left, right, root)
    void postOrderTraversal(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->val << " ";
    }

    // Level Order Traversal also known as BFS(Breadth First Search).
    // Inorder, Preorder and Postorder Traversals are DFS(Depth First Search).
};

int main()
{
    BinaryTree tree;

    cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrderTraversal(tree.root);
    cout << endl;

    return 0;
}
