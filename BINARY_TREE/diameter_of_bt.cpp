#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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

class Solution {
private:
    int height(struct Node* node) {
        //base case
        if (node == NULL) {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }

public:
    // Function to return the diameter of a Binary Tree.
    pair<int, int> diameterFast(Node* root) {
        //base case
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    int treeDiameter = obj.diameter(root);

    cout << "Diameter of the binary tree is: " << treeDiameter << endl;

    return 0;
}


// This code defines a binary tree data structure and a solution class that contains functions to calculate the diameter of a binary tree.

// The binary tree is represented using a struct called Node. Each Node has an integer data value and two pointers, left and right, which point to the left and right child nodes respectively. The struct also has a constructor that initializes the data value and sets the left and right pointers to NULL.

// The Solution class has a private helper function called height, which calculates the height of a given node in the binary tree. The height of a node is defined as the number of edges in the longest path from the node to a leaf node. The height function uses recursion to calculate the height of the left and right child nodes, and then returns the maximum height plus one.

// The public function diameterFast is used to calculate the diameter of the binary tree. The diameter of a binary tree is defined as the number of nodes in the longest path between any two leaf nodes. The diameterFast function uses recursion to calculate the diameter of the left and right child nodes, and then calculates three options for the diameter of the current node: 
// - Option 1: The diameter of the left child node.
// - Option 2: The diameter of the right child node.
// - Option 3: The sum of the heights of the left and right child nodes plus one.

// The function then returns a pair of integers, where the first integer represents the maximum diameter among the three options, and the second integer represents the height of the current node.

// The diameter function is a wrapper function that calls the diameterFast function and returns only the first integer of the pair, which represents the diameter of the binary tree.

// In summary, this code defines a binary tree data structure and provides a function to calculate the diameter of the binary tree. The diameter is calculated using recursion and dynamic programming techniques.