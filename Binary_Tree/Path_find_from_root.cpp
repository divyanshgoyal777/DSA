#include <iostream>
#include <vector>
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

    bool path(TreeNode *root, vector<int> &vec, int p)
    {
        if (root == nullptr)
        {
            return false;
        }
        vec.push_back(root->val);
        if (root->val == p)
        {
            for (int paths : vec)
            {
                cout << paths << endl;
            }
            return true;
        }
        if (path(root->left, vec, p) || path(root->right, vec, p))
        {
            return true;
        }
        vec.pop_back();
        return false;
    }
};

int main()
{
    BinaryTree tree;
    int p = 15;
    vector<int> vec;
    if(tree.path(tree.root, vec, p)){
        cout << "";
    }
    else{
        cout << "Path not found!" << endl;
    }
    return 0;
}
