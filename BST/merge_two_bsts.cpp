#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform an inorder traversal and store the elements in a vector.
void inorder(TreeNode<int>* root, vector<int>& in) {
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Function to merge two sorted arrays.
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans[k++] = a[i++];
        } else {
            ans[k++] = b[j++];
        }
    }
    
    while (i < a.size()) {
        ans[k++] = a[i++];
    }
    
    while (j < b.size()) {
        ans[k++] = b[j++];
    }

    return ans;
}

// Function to convert a sorted array to a balanced BST.
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

// Function to merge two BSTs and return the merged BST.
TreeNode<int>* mergeBST(TreeNode<int>* root1, TreeNode<int>* root2) {
    // Step 1: Store inorder traversals of both BSTs.
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Step 2: Merge the inorder traversals.
    vector<int> mergeArray = mergeArrays(bst1, bst2);

    // Step 3: Convert the merged array to a balanced BST.
    int start = 0;
    int end = mergeArray.size() - 1;

    return inorderToBST(start, end, mergeArray);
}

int main() {

    TreeNode<int>* root1 = new TreeNode<int>(2);
    root1->left = new TreeNode<int>(1);
    root1->right = new TreeNode<int>(3);

    TreeNode<int>* root2 = new TreeNode<int>(6);
    root2->left = new TreeNode<int>(5);
    root2->right = new TreeNode<int>(7);

    // Merge the two BSTs.
    TreeNode<int>* mergedBST = mergeBST(root1, root2);

    // Print the inorder traversal of the merged BST.
    vector<int> inorderTraversal;
    inorder(mergedBST, inorderTraversal);
    cout << "Inorder traversal of the merged BST: ";
    for (int val : inorderTraversal) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}


// This code is written in C++ and it defines several functions to merge two Binary Search Trees (BSTs) into a single BST.

// Let's start by understanding the `inorder` function. This function takes a pointer to a TreeNode object and a vector of integers as input. It performs an inorder traversal of the BST rooted at the given node and stores the values in the vector in sorted order. The function is implemented recursively. It first checks if the given node is NULL, which indicates an empty tree. If so, it simply returns. Otherwise, it recursively calls the `inorder` function on the left subtree, then pushes the value of the current node into the vector, and finally recursively calls the `inorder` function on the right subtree.

// Next, let's look at the `mergeArrays` function. This function takes two vectors of integers as input and merges them into a single sorted vector. It initializes an empty vector `ans` with a size equal to the sum of the sizes of the input vectors. It also initializes three variables `i`, `j`, and `k` to keep track of the indices of the elements in the input vectors and the merged vector, respectively. The function then enters a while loop that continues as long as both `i` and `j` are within the bounds of their respective vectors. Inside the loop, it compares the elements at indices `i` and `j` in the input vectors. If the element at index `i` is smaller, it is added to the merged vector at index `k`, and `i` and `k` are incremented. Otherwise, the element at index `j` is added to the merged vector at index `k`, and `j` and `k` are incremented. After the loop, there may be remaining elements in one of the input vectors. The function then enters two separate while loops to add these remaining elements to the merged vector. Finally, the merged vector is returned.

// Moving on to the `inorderToBST` function. This function takes three arguments: `start`, `end`, and a reference to a vector of integers. It is a recursive function that constructs a BST from a sorted array of integers. The base case is when `start` is greater than `end`, which indicates an empty range of values. In this case, the function returns NULL. Otherwise, it calculates the middle index of the range as `(start + end) / 2`. It creates a new TreeNode object with the value at the middle index of the vector and assigns it to the `root` pointer. It then recursively calls the `inorderToBST` function on the left half of the range, with `start` as the start index and `mid - 1` as the end index. The returned value is assigned to the `left` pointer of the `root` node. Similarly, it recursively calls the `inorderToBST` function on the right half of the range, with `mid + 1` as the start index and `end` as the end index. The returned value is assigned to the `right` pointer of the `root` node. Finally, the `root` node is returned.

// Lastly, let's understand the `mergeBST` function. This function takes two pointers to TreeNode objects as input, which represent the roots of two BSTs. It first declares two vectors `bst1` and `bst2` to store the inorder traversal of the two BSTs, respectively. It then calls the `inorder` function on each BST, passing the root and the corresponding vector as arguments. This populates the vectors with the values of the BSTs in sorted order. Next, it calls the `mergeArrays` function, passing the two vectors as arguments. This merges the two vectors into a single sorted vector. It then initializes `start` as 0 and `end` as the size of the merged vector minus 1. Finally, it calls the `inorderToBST` function, passing `start`, `end`, and the merged vector as arguments. This constructs a new BST from the merged vector and returns the root of the new BST.

// In summary, this code defines functions to merge two BSTs into a single BST. It does this by first performing an inorder traversal on each BST to obtain sorted vectors of values. It then merges these vectors into a single sorted vector and constructs a new BST from this merged vector.