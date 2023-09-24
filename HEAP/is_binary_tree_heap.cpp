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
    int countNodes(Node* root) {
        // Base case
        if (root == NULL)
            return 0;

        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }

    bool isCBT(Node* root, int index, int cnt) {
        if (root == NULL)
            return true;

        if (index >= cnt)
            return false;
        else {
            bool left = isCBT(root->left, 2 * index + 1, cnt);
            bool right = isCBT(root->right, 2 * index + 2, cnt);
            return (left && right);
        }
    }

    bool isMaxOrder(Node* root) {
        // Left node
        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->right == NULL)
            return (root->data > root->left->data);

        else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            return (left && right &&
                (root->data > root->left->data && root->data > root->right->data));
        }
    }

    bool isHeap(Node* tree) {
        int index = 0;
        int totalCount = countNodes(tree);
        if (isCBT(tree, index, totalCount) && isMaxOrder(tree)) {
            return true;
        }
        else
            return false;
    }
};

int main() {
    Solution solution;

    // Example usage:
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    bool isMaxHeap = solution.isHeap(root);

    if (isMaxHeap)
        cout << "The binary tree is a Max Heap." << endl;
    else
        cout << "The binary tree is not a Max Heap." << endl;

    // Don't forget to free the memory allocated for the tree nodes.
    // Add cleanup code here if needed.

    return 0;
}

// This code is a C++ implementation of a class called Solution. This class contains several functions that work together to determine if a given binary tree is a heap.

// The first function is countNodes, which takes a Node pointer as input and returns the number of nodes in the binary tree. It uses a recursive approach to count the nodes by adding 1 for the current node and recursively calling countNodes on the left and right subtrees.

// The second function is isCBT, which stands for "is Complete Binary Tree". It takes three parameters: a Node pointer, an index, and a count. It checks if the binary tree is a complete binary tree by comparing the index with the count. If the index is greater than or equal to the count, it means that the tree is not complete and the function returns false. Otherwise, it recursively calls isCBT on the left and right subtrees with updated indices and counts. The function returns true if both the left and right subtrees are complete binary trees.

// The third function is isMaxOrder, which checks if the binary tree satisfies the max-heap property. It takes a Node pointer as input and checks if the current node is greater than its left and right children. If the current node has no children, it returns true. If it has only a left child, it checks if the current node is greater than the left child. If it has both left and right children, it recursively calls isMaxOrder on the left and right subtrees and checks if the current node is greater than both of them. The function returns true if all these conditions are satisfied.

// The fourth function is isHeap, which takes a Node pointer as input and checks if the binary tree is a heap. It first calls countNodes to get the total number of nodes in the tree. Then, it calls isCBT and isMaxOrder to check if the tree is a complete binary tree and satisfies the max-heap property, respectively. If both conditions are true, it returns true. Otherwise, it returns false.

// Overall, this code uses recursive functions to count the nodes in the binary tree, check if it is a complete binary tree, and check if it satisfies the max-heap property. The isHeap function combines these checks to determine if the binary tree is a heap.
