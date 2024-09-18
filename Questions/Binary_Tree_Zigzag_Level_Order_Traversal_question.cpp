#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool lr = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
            if (!lr)
            {
                // reverse(level.begin(), level.end());
                vector<int> temp = level;
                level.clear();
                for (int nums : temp)
                {
                    level.insert(level.begin(), nums);
                }
            }
            result.push_back(level);
            lr = !lr;
        }
        return result;
    }
};

int main()
{
    BinaryTree tree;
    vector<vector<int>> result = tree.zigzagLevelOrder(tree.root);

    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
