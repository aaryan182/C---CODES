#include <bits/stdc++.h>
using namespace std;

// Define the structure of the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


Node* solve(Node* root, int &k, int node){
    // base case
    if(root == NULL)
        return NULL;
    
    if(root->data == node)
        return root;
    
    Node* leftAns = solve(root->left , k , node);
    Node* rightAns = solve(root->right , k , node);
    
    // wapas
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            // answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            // answer lock 
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
 
 
 
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root,k,node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    // Node to find the kth ancestor for
    int node = 7;

    // Value of k
    int k = 2; // Change this value to find different ancestors

    // Call the kthAncestor function to find the kth ancestor of the node
    int ancestor = kthAncestor(root, k, node);

    if (ancestor != -1) {
        std::cout << "The " << k << "th ancestor of node " << node << " is: " << ancestor << std::endl;
    } else {
        std::cout << "Node not found or no such ancestor exists." << std::endl;
    }

    // Don't forget to free the memory allocated for the tree nodes (you can use a separate function for this)

    return 0;
}


// This code is a recursive function that finds the kth ancestor of a given node in a binary tree.

// The function `solve` takes three parameters: `root`, `k`, and `node`. `root` is a pointer to the root of the binary tree, `k` is the number of ancestors to go back, and `node` is the value of the node whose ancestor we want to find.

// The function starts with a base case: if the `root` is `NULL`, it means we have reached the end of the tree and there are no more ancestors to find, so we return `NULL`.

// Next, the function checks if the `data` of the `root` is equal to the `node` we are looking for. If it is, it means we have found the node itself, so we return the `root`.

// If the `root` is not the node we are looking for, we recursively call the `solve` function on the left and right subtrees of the `root`. The results of these recursive calls are stored in the variables `leftAns` and `rightAns`, respectively.

// After the recursive calls, the function checks if `leftAns` is not `NULL` and `rightAns` is `NULL`. This means that the `node` we are looking for is in the left subtree but not in the right subtree. In this case, we decrement `k` by 1 and check if `k` is less than or equal to 0. If it is, it means we have found the kth ancestor, so we set `k` to `INT_MAX` (a very large value) to lock the answer and return the `root`. Otherwise, we return `leftAns`.

// Similarly, if `leftAns` is `NULL` and `rightAns` is not `NULL`, it means that the `node` we are looking for is in the right subtree but not in the left subtree. Again, we decrement `k` by 1 and check if `k` is less than or equal to 0. If it is, we have found the kth ancestor, so we set `k` to `INT_MAX` and return the `root`. Otherwise, we return `rightAns`.

// If none of the above conditions are met, it means that the `node` we are looking for is not in the current subtree, so we return `NULL`.

// The `kthAncestor` function takes three parameters: `root`, `k`, and `node`. It calls the `solve` function with these parameters and stores the result in the variable `ans`. If `ans` is `NULL` or the `data` of `ans` is equal to `node`, it means we have not found the kth ancestor, so we return -1. Otherwise, we return the `data` of `ans`, which is the value of the kth ancestor.