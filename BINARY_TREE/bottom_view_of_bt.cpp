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


// This code is a solution to a problem that involves finding the bottom view of a binary tree. The bottom view of a binary tree is defined as the set of nodes that are visible when looking at the tree from the bottom.

// The code starts by checking if the root of the tree is NULL. If it is, an empty vector is returned as there are no nodes in the tree.

// Next, a map called `topNode` is created. This map will store the horizontal distance (hd) of each node from the root, along with the value of the node. The horizontal distance is a measure of how far a node is from the root horizontally.

// A queue called `q` is also created. This queue will be used to perform a level order traversal of the tree. The queue initially contains a pair consisting of the root node and its horizontal distance, which is 0.

// The code then enters a while loop that continues until the queue is empty. In each iteration of the loop, the front element of the queue is removed and stored in a temporary pair called `temp`. The front node of the pair is then extracted and stored in a variable called `frontNode`, and the horizontal distance is stored in a variable called `hd`.

// The value of the front node is then added to the `topNode` map at the key corresponding to its horizontal distance.

// Next, the code checks if the front node has a left child. If it does, a pair consisting of the left child and `hd-1` is pushed into the queue. This represents moving one unit to the left horizontally from the current node. Similarly, if the front node has a right child, a pair consisting of the right child and `hd+1` is pushed into the queue. This represents moving one unit to the right horizontally from the current node.

// Once the while loop is finished, the code iterates over the `topNode` map using a range-based for loop. For each key-value pair in the map, the value (which represents the node's value) is added to the `ans` vector.

// Finally, the `ans` vector is returned, which contains the values of the nodes in the bottom view of the binary tree.