#include <bits/stdc++.h>
using namespace std;

// Define the structure for a binary tree node
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// APPROACH 1 USING INORDER TRAVERSAL

// Function to perform inorder traversal of the binary tree and store the elements in a vector
void inorderTraversal(BinaryTreeNode<int>* root, vector<int>& elements) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left, elements);
    elements.push_back(root->data);
    inorderTraversal(root->right, elements);
}

// Function to check if a binary tree is a BST
bool validateBST(BinaryTreeNode<int> *root) {
    // Store the elements of the binary tree in an array in sorted order
    vector<int> elements;
    inorderTraversal(root, elements);

    // Check if the elements in the array are sorted
    for (int i = 1; i < elements.size(); ++i) {
        if (elements[i] <= elements[i - 1]) {
            return false; // Not a BST
        }
    }

    return true; // It's a BST
}

int main() {

    // Create a binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(15);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(7);

    // Check if it's a BST
    if (validateBST(root)) {
        cout << "The given binary tree is a BST." << endl;
    } else {
        cout << "The given binary tree is not a BST." << endl;
    }

    // Clean up memory (free dynamically allocated nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}


// APPROACH 2 USING RECURSION 

// #include <bits/stdc++.h>
// using namespace std;

// // Define the structure for a binary tree node
// template <typename T>
// class BinaryTreeNode {
// public:
//     T data;
//     BinaryTreeNode* left;
//     BinaryTreeNode* right;

//     BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
// };

// // Function to check if a binary tree is a BST
// bool isBST(BinaryTreeNode<int> *root , int min, int max){
//     // Base case
//     if (root == nullptr)
//         return true;

//     // Check if the current node's data is within the valid range
//     if (root->data > min && root->data < max) {
//         // Recursively check the left and right subtrees
//         bool left = isBST(root->left, min, root->data);
//         bool right = isBST(root->right, root->data, max);
//         return left && right;
//     } else {
//         return false; // Node's data is not within the valid range
//     }
// }

// // Function to validate if a binary tree is a BST
// bool validateBST(BinaryTreeNode<int> *root) {
//     return isBST(root, INT_MIN, INT_MAX);
// }

// int main() {
//     // Example usage:
//     // Create a binary tree
//     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
//     root->left = new BinaryTreeNode<int>(5);
//     root->right = new BinaryTreeNode<int>(15);
//     root->left->left = new BinaryTreeNode<int>(3);
//     root->left->right = new BinaryTreeNode<int>(7);

//     // Check if it's a BST
//     if (validateBST(root)) {
//         cout << "The given binary tree is a BST." << endl;
//     } else {
//         cout << "The given binary tree is not a BST." << endl;
//     }

//     // Clean up memory (free dynamically allocated nodes)
//     delete root->left->left;
//     delete root->left->right;
//     delete root->left;
//     delete root->right;
//     delete root;

//     return 0;
// }


// This code is used to validate if a binary tree is a binary search tree (BST). 

// A binary search tree is a binary tree where the value of each node is greater than all the values in its left subtree and less than all the values in its right subtree. 

// The code uses a recursive approach to check if the given binary tree is a BST. 

// The `isBST` function takes three parameters: the root of the binary tree, the minimum value allowed for a node, and the maximum value allowed for a node. 

// The base case of the recursion is when the root is `nullptr`, which means we have reached the end of a subtree and it is considered a valid BST. In this case, the function returns `true`. 

// If the current node's data is within the valid range (greater than the minimum value and less than the maximum value), the function recursively checks the left and right subtrees. The left subtree is checked with the minimum value as the current node's data, and the right subtree is checked with the maximum value as the current node's data. 

// If both the left and right subtrees are valid BSTs, the function returns `true`. Otherwise, if the current node's data is not within the valid range, the function returns `false`. 

// The `validateBST` function is a wrapper function that calls the `isBST` function with the root of the binary tree and the minimum and maximum values allowed for a node, which are `INT_MIN` and `INT_MAX` respectively. 

// Finally, the `validateBST` function returns the result of the `isBST` function, which indicates whether the given binary tree is a BST or not.