// #include <iostream>
// using namespace std;

// class BinaryTree
// {
// public:
//     class TreeNode
//     {
//     public:
//         int val;
//         TreeNode *left;
//         TreeNode *right;

//         TreeNode(int data)
//         {
//             val = data;
//             left = nullptr;
//             right = nullptr;
//         }
//     };

//     TreeNode *root;

//     BinaryTree()
//     {
//         root = new TreeNode(1);
//         root->left = new TreeNode(2);
//         root->right = new TreeNode(3);
//         root->left->left = new TreeNode(4);
//         root->left->right = new TreeNode(5);
//         root->right->left = new TreeNode(6);
//         root->right->right = new TreeNode(7);
//         root->right->right->right = new TreeNode(11);
//         root->left->left->left = new TreeNode(8);
//         root->left->left->right = new TreeNode(10);
//         root->left->left->left->left = new TreeNode(9);
//     }

//     int height(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);
//         int height = max(leftHeight, rightHeight) + 1;
//         return height;
//     }

//     int diameter(TreeNode *root){
//         if(root == nullptr){
//             return 0;
//         }
//         int left_diameter = diameter(root->left);
//         int right_diameter = diameter(root->right);
//         int left_height = height(root->left);
//         int right_height = height(root->right);
//         int self = left_height + right_height + 1;
//         return max(self, max(left_diameter, right_diameter));
//     }
// };

// int main()
// {
//     BinaryTree tree;
//     cout << "Diameter of tree: " << tree.diameter(tree.root) << endl;

//     return 0;
// }

#include <iostream>
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
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        root->right->right->right = new TreeNode(11);
        root->left->left->left = new TreeNode(8);
        root->left->left->right = new TreeNode(10);
        root->left->left->left->left = new TreeNode(9);
    }

    int diameter()
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode *node, int &diameter)
    {
        if (node == nullptr)
            return 0;
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    BinaryTree tree;
    cout << "Diameter of tree: " << tree.diameter() << endl;

    return 0;
}
