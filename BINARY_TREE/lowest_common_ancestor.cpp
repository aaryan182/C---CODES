#include <bits/stdc++.h>
using namespace std;

// Define the structure of the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       // base case 
       if(root == NULL)
            return NULL;
        if(root->data == n1 || root->data == n2)
            return root;
        
        Node* leftAns = lca(root->left , n1,n2);
        Node* rightAns = lca(root->right , n1,n2);
        
        if(leftAns != NULL && rightAns != NULL)
            return root;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Create an instance of the Solution class
    Solution solution;

    int n1 = 5;
    int n2 = 1;

    // Call the lca function to find the lowest common ancestor
    Node* lcaNode = solution.lca(root, n1, n2);

    if (lcaNode != nullptr) {
        std::cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lcaNode->data << std::endl;
    } else {
        std::cout << "One or both nodes not found in the tree." << std::endl;
    }

    // Don't forget to free the memory allocated for the tree nodes (you can use a separate function for this)

    return 0;
}


// This code is a C++ implementation of a function to find the lowest common ancestor (LCA) of two nodes in a binary tree.

// The function `lca` takes three parameters: `root`, `n1`, and `n2`. `root` is a pointer to the root node of the binary tree, and `n1` and `n2` are the values of the two nodes whose LCA we want to find.

// The function starts with a base case: if the `root` is `NULL`, it means we have reached the end of the tree and there is no LCA, so we return `NULL`.

// Next, the function checks if the `data` of the `root` node is equal to either `n1` or `n2`. If it is, it means that the `root` node itself is one of the nodes we are looking for, so we return the `root`.

// If the `root` node is not one of the nodes we are looking for, we recursively call the `lca` function on the left and right subtrees of the `root` node. The results of these recursive calls are stored in the variables `leftAns` and `rightAns`, respectively.

// Next, the function checks if both `leftAns` and `rightAns` are not `NULL`. If they are not `NULL`, it means that `n1` and `n2` are present in different subtrees of the `root` node, so the `root` node itself is the LCA. In this case, we return the `root`.

// If only `leftAns` is not `NULL` and `rightAns` is `NULL`, it means that both `n1` and `n2` are present in the left subtree of the `root` node. In this case, we return `leftAns` as the LCA.

// If only `leftAns` is `NULL` and `rightAns` is not `NULL`, it means that both `n1` and `n2` are present in the right subtree of the `root` node. In this case, we return `rightAns` as the LCA.

// If both `leftAns` and `rightAns` are `NULL`, it means that neither `n1` nor `n2` are present in the subtree rooted at the `root` node. In this case, we return `NULL` as there is no LCA.

// Overall, this code uses a recursive approach to find the LCA of two nodes in a binary tree. It checks if the `root` node itself is one of the nodes, and if not, it recursively searches for the nodes in the left and right subtrees. It then combines the results of the recursive calls to determine the LCA.