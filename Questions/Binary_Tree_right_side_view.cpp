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
    }

    vector<int> rightSideView(TreeNode *root)
    {
        // if (root == nullptr)
        // {
        //     return;
        // }
        // cout << root->val << " ";
        // rightSideView(root->right);

        vector<int> result;
        vector<int> v;
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
            v.push_back(result.front());
            result.clear();
        }
        return v;
    }
};

int main()
{
    BinaryTree tree;
    vector<int> result;
    result = tree.rightSideView(tree.root);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}
