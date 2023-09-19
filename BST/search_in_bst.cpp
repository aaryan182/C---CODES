#include <bits/stdc++.h>
using namespace std;

// Definition of a Binary Tree Node
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to search for a value in a BST
template <typename T>
bool searchInBST(BinaryTreeNode<T>* root, T x) {
    // Base case: If the root is null, the value is not in the tree.
    if (root == nullptr)
        return false;

    // If the current node's data matches the target value, return true.
    if (root->data == x)
        return true;

    // If the target value is less than the current node's data,
    // recursively search in the left subtree.
    if (x < root->data)
        return searchInBST(root->left, x);
    // If the target value is greater, recursively search in the right subtree.
    else
        return searchInBST(root->right, x);
}

int main() {
    // Create a sample Binary Search Tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(15);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(7);
    root->right->left = new BinaryTreeNode<int>(12);
    root->right->right = new BinaryTreeNode<int>(18);

    int target = 7; // Value to search for

    // Call the searchInBST function to check if the target value exists in the BST
    bool found = searchInBST(root, target);

    // Display the result
    if (found)
        cout << target << " is found in the BST." << endl;
    else
        cout << target << " is not found in the BST." << endl;

    // Remember to free the allocated memory to prevent memory leaks
    // (You should implement a proper destructor for the tree in practice).
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
