#include <iostream>
#include <vector>
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
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->left->left->left = new TreeNode(8);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        root->right->left->right = new TreeNode(9);
    }

    vector<int> printLevel(TreeNode *root, int level)
    {
        queue<TreeNode *> q;
        vector<int> result;
        q.push(root);
        int count = 0;
        while (!q.empty())
        {
            count++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (count == level)
                {
                    result.push_back(temp->val);
                }
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
        }
        return result;
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
    int level = 3;
    vector<int> result = tree.printLevel(tree.root, level);
    for (int nums : result)
    {
        cout << nums << " ";
    }
    return 0;
}
