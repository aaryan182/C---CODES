#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to traverse the tree and find the left view nodes.
void solve(Node* root, vector<int>& ans, int level) {
    // Base case: If the current node is NULL, return.
    if (root == NULL)
        return;

    // If we have entered into a new level, add the current node's value to the result.
    if (level == ans.size())
        ans.push_back(root->data);

    // Recursively traverse the left and right subtrees.
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

// Main function to find the left view of the binary tree.
vector<int> leftView(Node* root) {
    vector<int> ans;
    solve(root, ans, 0); // Start the recursive traversal from the root at level 0.
    return ans;
}

int main() {
    // Create a sample Binary Tree for testing.
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = leftView(root);

    // Print the left view of the tree.
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}


// This code is for finding the left view of a binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

// The code starts with a function called `solve` which takes three parameters: `root`, `ans`, and `level`. The `root` parameter is a pointer to the root node of the binary tree. The `ans` parameter is a reference to a vector of integers which will store the left view of the tree. The `level` parameter is an integer which represents the current level of the tree.

// The first thing the code does is check if the `root` is `NULL`. If it is, it means we have reached the end of the tree and we return from the function.

// Next, the code checks if the `level` is equal to the size of the `ans` vector. If it is, it means we have entered into a new level of the tree and we need to add the current node's data to the `ans` vector. This is done by calling the `push_back` function on the `ans` vector and passing the `root` node's data as the argument.

// After that, the code recursively calls the `solve` function on the left and right child of the `root` node, incrementing the `level` by 1 each time. This is done to traverse the entire tree and find all the nodes in the left view.

// Finally, the code defines another function called `leftView` which takes a `root` parameter and returns a vector of integers. Inside this function, it creates an empty vector called `ans`. It then calls the `solve` function with the `root`, `ans`, and `0` as arguments. This will populate the `ans` vector with the left view of the tree. Finally, the `ans` vector is returned.