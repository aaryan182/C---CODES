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

TreeNode<int>* inorderToBST(int start, int end, vector<int>& in) {
    // Base case
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;

    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(start, mid - 1, in);
    root->right = inorderToBST(mid + 1, end, in);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderVal;
    // Store inorder -> sorted values
    inorder(root, inorderVal);
    return inorderToBST(0, inorderVal.size() - 1, inorderVal);
}

int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);

    TreeNode<int>* balancedRoot = balancedBst(root);

    // Print the inorder traversal of the balanced BST.
    vector<int> inorderTraversal;
    inorder(balancedRoot, inorderTraversal);
    cout << "Inorder traversal of balanced BST: ";
    for (int val : inorderTraversal) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

// This code is for converting a binary search tree (BST) into a balanced BST. 

// The `inorder` function is used to traverse the original BST in inorder fashion and store the values in a vector called `inorderVal`. In inorder traversal, we first visit the left subtree, then the root, and finally the right subtree. This ensures that the values are stored in ascending order in the `inorderVal` vector.

// The `inorderToBST` function is a recursive function that takes the start and end indices of the `inorderVal` vector and constructs a balanced BST from the values in that range. The base case for the recursion is when the start index is greater than the end index, in which case we return `NULL`. Otherwise, we calculate the mid index as the average of the start and end indices. We create a new `TreeNode` with the value at the mid index of `inorderVal` and recursively call `inorderToBST` for the left and right subtrees, passing the appropriate start and end indices. We assign the returned subtrees to the `left` and `right` pointers of the current root and return the root.

// The `balancedBst` function is the entry point of the code. It initializes an empty vector called `inorderVal` and calls the `inorder` function to populate it with the inorder traversal of the original BST. Then, it calls the `inorderToBST` function with the start index as 0 and the end index as the size of `inorderVal` minus 1, along with the `inorderVal` vector. This function returns the root of the balanced BST, which is then returned by the `balancedBst` function.