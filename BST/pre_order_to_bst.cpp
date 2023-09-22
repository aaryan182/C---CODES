#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    if (i >= preorder.size())
        return NULL;

    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

// Function to perform an inorder traversal and print the tree.
void inorder(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    BinaryTreeNode<int>* root = preorderToBST(preorder);

    // Print the inorder traversal of the resulting BST.
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
