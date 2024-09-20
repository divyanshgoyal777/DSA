#include <iostream>
using namespace std;

class BinarySearchTree
{
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int value)
        {
            data = value;
            left = right = nullptr;
        }
    };

    Node *root;

    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    Node *searchNode(Node *node, int value)
    {
        if (node == nullptr || node->data == value)
        {
            return node;
        }

        if (value < node->data)
        {
            return searchNode(node->left, value);
        }
        else{
            return searchNode(node->right, value);
        }
            
    }

    Node *findMinNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Case 1: Node has no children (leaf node)
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            // Case 2: Node has only one child
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Node has two children
            // Find the in-order successor (smallest value in the right subtree)
            Node *temp = findMinNode(node->right);
            // Replace the node's value with the in-order successor's value
            node->data = temp->data;
            // Delete the in-order successor
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    bool search(int value)
    {
        return searchNode(root, value) != nullptr;
    }

    void remove(int value)
    {
        root = deleteNode(root, value);
    }

    void inOrder()
    {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    cout << "In-order traversal of the BST: ";
    bst.inOrder();
    int searchValue = 40;
    if (bst.search(searchValue))
    {
        cout << searchValue << " is found in the BST" << endl;
    }
    else
    {
        cout << searchValue << " is not found in the BST" << endl;
    }
    bst.remove(70);
    cout << "In-order traversal after deleting 70: ";
    bst.inOrder();

    return 0;
}
