#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
private:
    pair<int, bool> isBalancedHelper(Node* root) {
        // Base case
        if (root == nullptr) {
            return make_pair(0, true);
        }

        // Recursively check left subtree
        pair<int, bool> leftResult = isBalancedHelper(root->left);
        if (!leftResult.second) {
            return make_pair(-1, false); // Left subtree is not balanced
        }

        // Recursively check right subtree
        pair<int, bool> rightResult = isBalancedHelper(root->right);
        if (!rightResult.second) {
            return make_pair(-1, false); // Right subtree is not balanced
        }

        // Check if the current tree is balanced
        bool isCurrentBalanced = abs(leftResult.first - rightResult.first) <= 1;
        int currentHeight = max(leftResult.first, rightResult.first) + 1;

        return make_pair(currentHeight, isCurrentBalanced);
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        pair<int, bool> result = isBalancedHelper(root);
        return result.second;
    }
};

int main() {
    // Creating a sample balanced binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution obj;
    bool balanced = obj.isBalanced(root);

    if (balanced) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}



// This code is a C++ implementation of a function that checks whether a binary tree is balanced or not. 

// The binary tree is represented using a struct called Node, which has three members: data, left, and right. The data member stores the value of the node, while the left and right members are pointers to the left and right child nodes, respectively. 

// The main function of the code is `isBalanced`, which takes a pointer to the root of the binary tree as input and returns a boolean value indicating whether the tree is balanced or not. 

// The `isBalanced` function calls a helper function called `isBalancedHelper` to perform the actual checking. The `isBalancedHelper` function takes a pointer to the current node as input and returns a pair of values: the height of the subtree rooted at the current node and a boolean value indicating whether the subtree is balanced or not. 

// The `isBalancedHelper` function uses a recursive approach to check the balance of the binary tree. It first checks the balance of the left subtree by calling itself recursively on the left child of the current node. If the left subtree is not balanced, it returns a pair of values (-1, false) to indicate that the subtree is not balanced. 

// Next, it checks the balance of the right subtree by calling itself recursively on the right child of the current node. If the right subtree is not balanced, it returns a pair of values (-1, false) to indicate that the subtree is not balanced. 

// If both the left and right subtrees are balanced, the function checks the balance of the current tree by comparing the heights of the left and right subtrees. If the absolute difference between the heights is greater than 1, the current tree is not balanced and the function returns a pair of values (-1, false). Otherwise, the current tree is balanced and the function returns a pair of values (currentHeight, true), where currentHeight is the maximum height of the left and right subtrees plus 1. 

// Finally, the `isBalanced` function calls the `isBalancedHelper` function on the root of the binary tree and returns the boolean value indicating whether the tree is balanced or not.