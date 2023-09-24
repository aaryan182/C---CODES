#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform an in-order traversal of the BST and store elements in a vector.
void inOrderTraversal(TreeNode* root, vector<int>& elements) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left, elements);
    elements.push_back(root->data);
    inOrderTraversal(root->right, elements);
}

// Function to build a min-heap using an array of elements.
void buildMinHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; i--) {
        // Perform min-heapify from the last non-leaf node to the root.
        int parent = i;
        while (true) {
            int leftChild = 2 * parent + 1;
            int rightChild = 2 * parent + 2;
            int smallest = parent;

            if (leftChild < n && arr[leftChild] < arr[smallest])
                smallest = leftChild;

            if (rightChild < n && arr[rightChild] < arr[smallest])
                smallest = rightChild;

            if (smallest != parent) {
                swap(arr[parent], arr[smallest]);
                parent = smallest;
            } else {
                break;
            }
        }
    }
}

// Function to convert a BST to a min-heap.
void BSTtoMinHeap(TreeNode* root) {
    // Step 1: Perform an in-order traversal to get elements in sorted order.
    vector<int> elements;
    inOrderTraversal(root, elements);

    // Step 2: Build a min-heap using the sorted elements.
    buildMinHeap(elements);

    // Update the BST with the elements in min-heap order.
    int index = 0;
    updateBST(root, elements, index);
}

// Function to update the BST with min-heap order elements.
void updateBST(TreeNode* root, vector<int>& elements, int& index) {
    if (root == NULL)
        return;

    // Update left subtree
    updateBST(root->left, elements, index);

    // Update current node with the min-heap element
    root->data = elements[index++];
    
    // Update right subtree
    updateBST(root->right, elements, index);
}

// Function to print the elements of a min-heap.
void printMinHeap(vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to print the elements of a BST.
void printBST(TreeNode* root) {
    if (root == NULL)
        return;

    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "BST Elements: ";
    printBST(root);
    cout << endl;

    BSTtoMinHeap(root);

    cout << "Min-Heap Elements: ";
    vector<int> minHeapElements;
    inOrderTraversal(root, minHeapElements);
    printMinHeap(minHeapElements);

    return 0;
}


// This code is used to convert a Binary Search Tree (BST) into a min-heap. 

// The first function, `inOrderTraversal`, performs an in-order traversal of the BST and stores the elements in a vector called `elements`. In an in-order traversal, we visit the left subtree, then the current node, and finally the right subtree. This ensures that the elements are stored in sorted order.

// The second function, `buildMinHeap`, takes the `elements` vector and builds a min-heap using the elements. A min-heap is a complete binary tree where the value of each node is smaller than or equal to the values of its children. The function starts from the last non-leaf node and performs a process called min-heapify. In min-heapify, we compare the parent node with its left and right children and swap the parent with the smallest child if necessary. This process is repeated until the parent is smaller than both its children or until we reach a leaf node.

// The third function, `BSTtoMinHeap`, is the main function that converts the BST to a min-heap. It first calls the `inOrderTraversal` function to get the elements in sorted order. Then, it calls the `buildMinHeap` function to build a min-heap using the sorted elements. Finally, it calls the `updateBST` function to update the BST with the elements in min-heap order.

// The fourth function, `updateBST`, is a recursive function that updates the BST with the elements in min-heap order. It performs an in-order traversal of the BST and updates each node with the corresponding element from the `elements` vector. The `index` parameter is used to keep track of the current index in the `elements` vector.

// Overall, this code converts a BST to a min-heap by performing an in-order traversal to get the elements in sorted order, building a min-heap using the sorted elements, and updating the BST with the elements in min-heap order.