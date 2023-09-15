#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function to traverse the tree and find the right view nodes.
    void solve(Node* root, vector<int>& ans, int level) {
        // Base case: If the current node is NULL, return.
        if (root == NULL)
            return;

        // If we have entered into a new level, add the current node's value to the result.
        if (level == ans.size())
            ans.push_back(root->data);

        // Recursively traverse the right subtree first, then the left subtree.
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }

    // Main function to find the right view of the binary tree.
    vector<int> rightView(Node* root) {
        vector<int> ans;
        solve(root, ans, 0); // Start the recursive traversal from the root at level 0.
        return ans;
    }
};

int main() {
    // Create a sample Binary Tree for testing.
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;
    vector<int> result = solution.rightView(root);

    // Print the right view of the tree.
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}


// This code is a solution to a problem that requires finding the elements of the right view of a binary tree. The right view of a binary tree is the set of nodes that are visible when looking at the tree from the right side.

// The code defines a class called Solution, which contains a public function called rightView. This function takes a pointer to the root of the binary tree as input and returns a vector of integers representing the elements of the right view.

// The rightView function calls another function called solve, which is a recursive function that performs a depth-first search on the binary tree. The solve function takes three parameters: the current node, a reference to the vector of integers that will store the elements of the right view, and the current level of the tree.

// The solve function has two base cases. The first base case checks if the current node is NULL, which means we have reached the end of a branch and there are no more nodes to process. In this case, the function simply returns.

// The second base case checks if the current level is equal to the size of the vector of integers. This means that we have entered a new level of the tree that has not been visited before. In this case, the function adds the data of the current node to the vector of integers, as this node is visible from the right side.

// After the base cases, the solve function makes two recursive calls. The first recursive call is to the right child of the current node, passing the same vector of integers and the current level plus one. This ensures that we explore the right subtree before the left subtree, as we are interested in the right view.

// The second recursive call is to the left child of the current node, again passing the same vector of integers and the current level plus one. This ensures that we explore the left subtree after the right subtree.

// Finally, the rightView function initializes an empty vector of integers called ans and calls the solve function with the root of the binary tree, the ans vector, and the initial level of 0. After the solve function returns, the rightView function simply returns the ans vector, which contains the elements of the right view of the binary tree.
