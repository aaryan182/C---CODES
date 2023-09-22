#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

class info {
public:
    int maxi, mini, size;
    bool isBST;
    info() : maxi(INT_MIN), mini(INT_MAX), size(0), isBST(true) {}
};

info solve(TreeNode<int>* root, int& ans) {
    // Base case
    if (root == NULL)
        return info();

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }

    // Answer update
    if (currNode.isBST) {
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode<int>* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main() {

    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(8);
    root->right->right = new TreeNode<int>(7);

    int largestBSTSize = largestBST(root);

    cout << "Size of the largest BST in the given binary tree: " << largestBSTSize << endl;

    return 0;
}


// This code is used to find the size of the largest Binary Search Tree (BST) in a given binary tree.

// The code defines a class called `info` which stores information about a node in the binary tree. It has four member variables: `maxi`, `mini`, `size`, and `isBST`. 

// - `maxi` stores the maximum value in the subtree rooted at the current node.
// - `mini` stores the minimum value in the subtree rooted at the current node.
// - `size` stores the size of the subtree rooted at the current node.
// - `isBST` is a boolean variable that indicates whether the subtree rooted at the current node is a valid BST.

// The `info` class has a default constructor that initializes `maxi` to the minimum possible integer value (`INT_MIN`), `mini` to the maximum possible integer value (`INT_MAX`), `size` to 0, and `isBST` to `true`.

// The `solve` function is a recursive function that takes a pointer to the root of the binary tree and a reference to an integer `ans` (which will store the size of the largest BST). 

// The base case of the recursion is when the root is `NULL`, in which case the function returns an instance of the `info` class with default values.

// In the recursive case, the function calls itself recursively on the left and right subtrees and stores the returned `info` objects in the `left` and `right` variables.

// Then, a new `info` object called `currNode` is created to store the information about the current node. 

// The `size` of the `currNode` is calculated by adding the sizes of the left and right subtrees plus 1 (for the current node).

// The `maxi` of the `currNode` is set to the maximum value between the data of the current node and the `maxi` of the right subtree.

// The `mini` of the `currNode` is set to the minimum value between the data of the current node and the `mini` of the left subtree.

// The `isBST` of the `currNode` is set to `true` if the left and right subtrees are valid BSTs and the data of the current node is greater than the maximum value in the left subtree and less than the minimum value in the right subtree. Otherwise, it is set to `false`.

// Finally, if the `isBST` of the `currNode` is `true`, the `ans` is updated to the maximum value between the current `ans` and the `size` of the `currNode`.

// The `solve` function returns the `currNode`.

// The `largestBST` function is a wrapper function that takes a pointer to the root of the binary tree and returns the size of the largest BST in the tree.

// It initializes a variable `maxSize` to 0 and calls the `solve` function with the root and `maxSize` as arguments. It then returns the value of `maxSize`.

