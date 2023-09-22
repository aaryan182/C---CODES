#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

void inorder(TreeNode<int>* root, vector<int>& in) {
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    vector<int> inorderVal;
    // Store inorder -> sorted values
    inorder(root, inorderVal);
    int n = inorderVal.size();

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newRoot;

    for (int i = 1; i < n; i++) {
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}

int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(5);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);

    TreeNode<int>* flattenedRoot = flatten(root);

    // Print the flattened tree (linked list).
    TreeNode<int>* current = flattenedRoot;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->right;
    }

    return 0;
}


// This code is a function that takes a binary tree as input and returns a flattened version of the tree. 

// The function `inorder` is a helper function that performs an inorder traversal of the binary tree and stores the values in a vector called `inorderVal`. In an inorder traversal, we visit the left subtree, then the root, and finally the right subtree. 

// The `inorder` function takes three parameters: the root of the current subtree, the target value, and the vector to store the inorder values. 

// First, the function checks if the root is NULL. If it is, it means we have reached the end of the subtree and we return. 

// Next, the function recursively calls itself on the left subtree of the current root. This will traverse the left subtree in an inorder manner. 

// Then, the function pushes the value of the current root into the `in` vector. This is done to store the values in the inorder traversal order. 

// Finally, the function recursively calls itself on the right subtree of the current root. This will traverse the right subtree in an inorder manner. 

// After the `inorder` function is called, the `flatten` function creates a new vector called `inorderVal` to store the inorder values of the binary tree. 

// Then, it creates a new root node for the flattened tree using the first value in the `inorderVal` vector. 

// Next, it creates a pointer called `curr` and sets it to point to the new root node. 

// Then, it iterates over the remaining values in the `inorderVal` vector starting from index 1. 

// For each value, it creates a new node called `temp` with the value. 

// Then, it sets the left child of `curr` to NULL and the right child of `curr` to `temp`. 

// Finally, it updates `curr` to point to `temp` and repeats the process for the next value in the `inorderVal` vector. 

// After the loop, it sets the left and right child of `curr` to NULL to indicate the end of the flattened tree. 

// Finally, it returns the new root node of the flattened tree.