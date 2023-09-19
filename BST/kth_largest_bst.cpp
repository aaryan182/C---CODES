#include <bits/stdc++.h>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Helper function for finding the kth largest element
void kthLargestUtil(TreeNode* root, int& k, int& result) {
    if (root == nullptr || k == 0) {
        return;
    }

    // Recursively explore the right subtree (reverse inorder)
    kthLargestUtil(root->right, k, result);

    // Decrement k with each visited node
    k--;

    // If k becomes zero, we have found the kth largest element
    if (k == 0) {
        result = root->data;
        return;
    }

    // Explore the left subtree
    kthLargestUtil(root->left, k, result);
}

// Function to find the kth largest element in a BST
int kthLargest(TreeNode* root, int k) {
    int result = -1;
    kthLargestUtil(root, k, result);
    return result;
}

int main() {
    // Example usage:
    // Create a binary search tree
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Find the kth largest element (k = 3 in this example)
    int k = 3;
    int kthLargestElement = kthLargest(root, k);

    if (kthLargestElement != -1) {
        cout << "The " << k << "th largest element in the BST is: " << kthLargestElement << endl;
    } else {
        cout << "No kth largest element found for the given k." << endl;
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


// This code is used to find the kth largest element in a Binary Search Tree (BST). 

// The code consists of two functions: `kthLargestUtil` and `kthLargest`.

// The `kthLargestUtil` function is a recursive function that takes three parameters: the root of the BST, the value of k, and a reference to the result variable. 

// The function first checks if the root is null or if k is equal to 0. If either of these conditions is true, it means that we have reached the end of the tree or have already found the kth largest element, so the function returns.

// Next, the function recursively explores the right subtree of the current node in a reverse inorder traversal. This means that it visits the right subtree first, then the current node, and finally the left subtree. This is done by calling the `kthLargestUtil` function with the right child of the current node as the new root.

// After exploring the right subtree, the function decrements the value of k by 1. This is done to keep track of the number of nodes visited so far.

// Next, the function checks if k has become 0. If it has, it means that we have found the kth largest element. In this case, the function assigns the value of the current node to the result variable and returns.

// If k is still greater than 0, it means that we have not yet found the kth largest element and need to explore the left subtree. This is done by calling the `kthLargestUtil` function with the left child of the current node as the new root.

// The `kthLargest` function is a wrapper function that takes the root of the BST and the value of k as parameters. It initializes the result variable to -1 and then calls the `kthLargestUtil` function with these parameters. Finally, it returns the value of the result variable.

// In summary, the code uses a recursive approach to find the kth largest element in a BST. It explores the right subtree first in a reverse inorder traversal, decrements the value of k with each visited node, and stops when k becomes 0, indicating that the kth largest element has been found.