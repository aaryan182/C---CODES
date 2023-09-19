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

// Function to find the kth smallest element in a BST
int solve(BinaryTreeNode<int>* root, int& i, int k) {
    // Base case
    if (root == nullptr)
        return -1;

    int left = solve(root->left, i, k);
    if (left != -1)
        return left;

    i++;
    if (i == k)
        return root->data;

    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0; // Counter to keep track of the number of visited nodes
    return solve(root, i, k);
}

int main() {
    // Example usage:
    // Create a binary search tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(5);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(7);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right->right = new BinaryTreeNode<int>(8);

    // Find the kth smallest element (k = 3 in this example)
    int k = 3;
    int kthSmallestElement = kthSmallest(root, k);

    cout << "The " << k << "th smallest element in the BST is: " << kthSmallestElement << endl;

    // Clean up memory (free dynamically allocated nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}


// This code is a recursive function that finds the kth smallest element in a binary search tree.

// The function `solve` takes three parameters: `root`, `i`, and `k`. `root` is a pointer to the root of the binary search tree, `i` is a reference to an integer that keeps track of the number of visited nodes, and `k` is the position of the element we want to find.

// The function starts with a base case: if the `root` is `nullptr` (i.e., the tree is empty), it returns -1.

// Next, the function recursively calls itself on the left subtree of the `root` and assigns the result to the variable `left`. This step is important because it allows us to traverse the tree in an inorder manner, visiting the left subtree first.

// If the `left` is not -1 (i.e., we have found the kth smallest element in the left subtree), the function immediately returns `left`. This is because we have already found the kth smallest element and there is no need to continue searching.

// If the `left` is -1, it means we have not found the kth smallest element in the left subtree. In this case, we increment the `i` by 1 to keep track of the number of visited nodes. If the `i` is equal to `k`, it means we have found the kth smallest element and we return the `root->data`.

// If the `i` is not equal to `k`, it means we have not found the kth smallest element yet. In this case, we recursively call the `solve` function on the right subtree of the `root` and return the result.

// The `kthSmallest` function is a wrapper function that initializes the `i` to 0 and calls the `solve` function with the `root`, `i`, and `k` as arguments. It then returns the result of the `solve` function.

// In summary, this code uses recursion to traverse the binary search tree in an inorder manner and find the kth smallest element. It keeps track of the number of visited nodes using a counter (`i`) and returns the kth smallest element when it is found.