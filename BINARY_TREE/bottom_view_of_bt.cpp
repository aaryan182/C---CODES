#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to return a list of nodes visible from the bottom view 
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> bottomNode; // Map to store bottom nodes for each horizontal distance.
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0)); // Push the root with hd (horizontal distance) 0.

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;

            // Update the bottomNode map with the current node's value for its horizontal distance.
            bottomNode[hd] = frontNode->data;

            // Process left and right children, adjusting the horizontal distance.
            if (frontNode->left)
                q.push(make_pair(frontNode->left, hd - 1));
            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd + 1));
        }

        // Populate the result vector with bottom nodes in order of their horizontal distance.
        for (auto i : bottomNode) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    // Create a sample Binary Tree for testing.
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);

    Solution solution;
    vector<int> result = solution.bottomView(root);

    // Print the nodes visible from the bottom view.
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}


// This code is a C++ implementation of a function that returns a list of nodes visible from the bottom view of a binary tree.

// The function takes a pointer to the root node of the binary tree as input and returns a vector of integers.

// First, the code checks if the root node is NULL. If it is, an empty vector is returned.

// Next, a map called `bottomNode` is created. This map will store the bottom nodes for each horizontal distance. The horizontal distance is the distance of a node from the root node in the horizontal direction.

// A queue called `q` is also created. This queue will be used for a breadth-first search traversal of the binary tree.

// The root node is pushed into the queue with a horizontal distance of 0.

// The code then enters a while loop that continues until the queue is empty. In each iteration of the loop, the front element of the queue is removed and stored in a temporary pair called `temp`. The first element of the pair is the node, and the second element is the horizontal distance.

// The code then updates the `bottomNode` map with the value of the current node for its horizontal distance.

// Next, the code checks if the current node has a left child. If it does, the left child is pushed into the queue with a horizontal distance that is one less than the current node's horizontal distance. This is because the left child is one unit to the left of the current node.

// Similarly, if the current node has a right child, it is pushed into the queue with a horizontal distance that is one more than the current node's horizontal distance. This is because the right child is one unit to the right of the current node.

// Once the while loop is finished, the `bottomNode` map contains the bottom nodes for each horizontal distance. The code then populates the result vector `ans` with the bottom nodes in order of their horizontal distance.

// Finally, the `ans` vector is returned as the output of the function.