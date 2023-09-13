#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
public:
    pair<bool, int> isSumTreeFast(Node* root)
    {
        // base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);

        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        bool condn = root->data == leftAns.second + rightAns.second;

        pair<bool, int> ans;

        if (isLeftSumTree && isRightSumTree && condn)
        {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }

    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};

int main() {
    // Creating a sample Sum Tree
    Node* root = new Node{10};
    root->left = new Node{4};
    root->right = new Node{6};
    root->left->left = new Node{2};
    root->left->right = new Node{2};

    Solution obj;
    bool isSumTree = obj.isSumTree(root);

    if (isSumTree) {
        cout << "The binary tree is a Sum Tree." << endl;
    } else {
        cout << "The binary tree is not a Sum Tree." << endl;
    }

    return 0;
}


// This code defines a struct called `Node` which represents a node in a binary tree. Each node has an integer value (`data`) and two pointers (`left` and `right`) to its left and right child nodes.

// The code also defines a class called `Solution` which contains two functions: `isSumTreeFast` and `isSumTree`.

// The `isSumTreeFast` function takes a `Node` pointer as input and returns a pair of values: a boolean value indicating whether the tree rooted at the given node is a sum tree, and an integer value representing the sum of all the nodes in the tree.

// The function starts with a base case: if the given node is `NULL`, it means that the tree is empty, so the function returns a pair with `true` as the boolean value and `0` as the sum.

// Next, the function checks if the given node is a leaf node (i.e., it has no children). If so, it returns a pair with `true` as the boolean value and the node's value as the sum.

// If the given node is not a leaf node, the function recursively calls itself on the left and right child nodes to get the results for those subtrees.

// The function then checks if both the left and right subtrees are sum trees (i.e., their boolean values are `true`). It also checks if the sum of the left and right subtrees is equal to the value of the current node. If both conditions are true, it sets the boolean value of the result pair to `true` and the sum value to twice the value of the current node. Otherwise, it sets the boolean value to `false`.

// Finally, the function returns the result pair.

// The `isSumTree` function is a wrapper function that calls `isSumTreeFast` on the root node of the tree and returns only the boolean value of the result pair.

// In summary, this code checks if a given binary tree is a sum tree, where a sum tree is defined as a tree in which the value of each node is equal to the sum of the values of its left and right child nodes.