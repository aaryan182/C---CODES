#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

void inorder(BinaryTreeNode<int>* root, vector<int>& in) {
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorderVal;
    // Store inorder -> sorted values
    inorder(root, inorderVal);
    // Use two-pointer approach to check if a pair exists
    int i = 0, j = inorderVal.size() - 1;

    while (i < j) {
        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target)
            return true;
        else if (sum > target)
            j--;
        else
            i++;
    }
    return false;
}

int main() {
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(8);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(9);

    int target = 10;
    bool result = twoSumInBST(root, target);

    if (result)
        cout << "There is a pair in the BST that sums up to " << target << endl;
    else
        cout << "No pair found in the BST that sums up to " << target << endl;

    return 0;
}


// it aims to find if there are two nodes in a binary search tree (BST) that sum up to a given target value.

// The code consists of two functions: `inorder` and `twoSumInBST`.

// The `inorder` function is a recursive function that performs an inorder traversal of the BST. In inorder traversal, we visit the left subtree, then the root, and finally the right subtree. The function takes three parameters: the root of the current subtree, the target value, and a vector to store the inorder traversal values.

// The function first checks if the root is NULL, which means we have reached the end of the subtree and there are no more nodes to visit. In that case, the function simply returns.

// If the root is not NULL, the function recursively calls itself on the left subtree, passing the left child of the current root as the new root. This step ensures that we visit all the nodes in the left subtree before visiting the root.

// Next, the function pushes the data of the current root node into the vector. This step is important because we want to store the values of the BST in sorted order.

// Finally, the function recursively calls itself on the right subtree, passing the right child of the current root as the new root. This step ensures that we visit all the nodes in the right subtree after visiting the root.

// The `twoSumInBST` function is the main function that checks if there are two nodes in the BST that sum up to the target value. It takes two parameters: the root of the BST and the target value.

// First, the function declares a vector called `inorderVal` to store the inorder traversal values of the BST.

// Then, it calls the `inorder` function, passing the root of the BST and the `inorderVal` vector as arguments. This step populates the `inorderVal` vector with the sorted values of the BST.

// After that, the function initializes two pointers `i` and `j` to the start and end of the `inorderVal` vector, respectively.

// The function enters a while loop that continues as long as `i` is less than `j`. This loop is used to find the pair of values that sum up to the target value.

// Inside the loop, the function calculates the sum of the values at indices `i` and `j` in the `inorderVal` vector.

// If the sum is equal to the target value, the function returns true, indicating that a pair of values has been found.

// If the sum is greater than the target value, the function decrements `j` by 1, moving the pointer to the left in the sorted vector.

// If the sum is less than the target value, the function increments `i` by 1, moving the pointer to the right in the sorted vector.

// If the while loop completes without finding a pair of values that sum up to the target value, the function returns false.

// In summary, the code performs an inorder traversal of the BST to obtain the sorted values, and then uses a two-pointer approach to find a pair of values that sum up to the target value.