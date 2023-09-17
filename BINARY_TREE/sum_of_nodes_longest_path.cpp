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
    void solve(Node* root , int sum , int &maxSum, int len , int &maxLen){
        // base case
        if(root == NULL){
            if(len>maxLen){
            maxLen = len;
            maxSum = sum;
            }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }
    
    sum = sum + root->data;
    
    solve(root->left , sum , maxSum, len+1,maxLen);
    solve(root->right , sum , maxSum, len+1,maxLen);

    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    // Create an instance of the Solution class
    Solution solution;

    // Call the sumOfLongRootToLeafPath function
    int result = solution.sumOfLongRootToLeafPath(root);

    // Display the result
    std::cout << "Maximum sum of long root-to-leaf path: " << result << std::endl;

    // Don't forget to free the memory allocated for the tree nodes (you can use a separate function for this)
    
    return 0;
}



// This code is a solution to find the sum of the longest root-to-leaf path in a binary tree.

// The `solve` function is a recursive function that takes in the root of the current subtree, the current sum of the path, the maximum sum found so far, the length of the current path, and the maximum length found so far.

// The base case of the recursion is when the root is NULL, which means we have reached the end of a path. In this case, we check if the length of the current path is greater than the maximum length found so far. If it is, we update the maximum length and maximum sum with the current length and sum. If the length is equal to the maximum length, we update the maximum sum with the maximum of the current sum and the maximum sum.

// If the root is not NULL, we add the value of the current node to the current sum. Then, we recursively call the `solve` function for the left and right subtrees, passing in the updated sum, length, and maximum values.

// In the `sumOfLongRootToLeafPath` function, we initialize the length, maximum length, sum, and maximum sum variables. Then, we call the `solve` function with the root of the tree and the initial values. Finally, we return the maximum sum found.

// Overall, this code uses recursion to traverse the binary tree and keep track of the maximum sum and length of the root-to-leaf paths. It updates the maximum sum and length whenever a longer path is found.