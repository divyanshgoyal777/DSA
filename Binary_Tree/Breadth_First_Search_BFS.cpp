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
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        root->left->left->left = new TreeNode(8);
        root->left->left->right = new TreeNode(10);
        root->left->left->left->left = new TreeNode(9);
    }

    vector<int> bfs(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                result.push_back(temp->val);
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
};

int main()
{
    BinaryTree tree;
    vector<int> result = tree.bfs(tree.root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}