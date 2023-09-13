#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    // Function to find the height of a binary tree.
    int height(struct Node* node){
        // base case 
        if(node == NULL){
            return 0;
        }
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
};

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    int treeHeight = obj.height(root);

    cout << "Height of the binary tree is: " << treeHeight << endl;

    return 0;
}




// This code defines a binary tree data structure using a struct called Node. Each Node has an integer data value and two pointers, one for the left child and one for the right child.

// The class Solution contains a function called height, which takes a Node pointer as input and returns the height of the binary tree.

// The height of a binary tree is defined as the number of edges in the longest path from the root to a leaf node. In other words, it is the maximum depth of the tree.

// The height function uses recursion to calculate the height of the binary tree. It starts with a base case, which checks if the current node is NULL. If it is, it means we have reached a leaf node and the height is 0.

// If the current node is not NULL, the function recursively calls itself on the left and right child nodes. This calculates the height of the left and right subtrees.

// The heights of the left and right subtrees are stored in the variables "left" and "right" respectively.

// The height of the binary tree is then calculated by taking the maximum of the left and right subtree heights and adding 1 (to account for the current node).

// Finally, the height of the binary tree is returned as the answer.