#include <bits/stdc++.h>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the Lowest Common Ancestor (LCA) in a BST
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q) {
    // Base case
    if (root == nullptr)
        return nullptr;

    if (root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);

    if (root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);

    return root;
}

int main() {
    // Example usage:
    // Create a binary search tree
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Nodes for which we want to find the LCA
    TreeNode *P = root->left->left; // Node with value 5
    TreeNode *Q = root->left->right; // Node with value 15

    // Find the Lowest Common Ancestor (LCA) of P and Q
    TreeNode *lca = LCAinaBST(root, P, Q);

    if (lca != nullptr) {
        cout << "The Lowest Common Ancestor (LCA) of " << P->data << " and " << Q->data << " is: " << lca->data << endl;
    } else {
        cout << "No LCA found for the given nodes." << endl;
    }

    // Clean up memory (free dynamically allocated nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}


// This code is a recursive function that finds the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST).

// The function takes three parameters: the root of the BST, and two nodes P and Q. The goal is to find the LCA of P and Q in the BST.

// The function starts with a base case, which checks if the root is null. If the root is null, it means we have reached the end of the tree and haven't found the LCA, so we return null.

// Next, the function checks if the data of the root is less than both P and Q. If it is, it means that both P and Q are in the right subtree of the root. In this case, we recursively call the function with the right child of the root as the new root, and the same P and Q nodes.

// If the data of the root is greater than both P and Q, it means that both P and Q are in the left subtree of the root. In this case, we recursively call the function with the left child of the root as the new root, and the same P and Q nodes.

// If neither of the above conditions is true, it means that the root is the LCA of P and Q. We return the root.

// The function continues to recursively call itself until it finds the LCA or reaches the base case.

// Overall, this code efficiently finds the LCA of two nodes in a BST by recursively traversing the tree based on the values of the nodes.