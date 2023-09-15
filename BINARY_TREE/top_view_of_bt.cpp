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
    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> topNode; // Map to store top nodes for each horizontal distance.
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0)); // Push the root with hd (horizontal distance) 0.

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;

            // If no node is present at this horizontal distance, add it to the topNode map.
            if (topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode->data;

            // Process left and right children, adjusting the horizontal distance.
            if (frontNode->left)
                q.push(make_pair(frontNode->left, hd - 1));
            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd + 1));
        }

        // Populate the result vector with top nodes in order of their horizontal distance.
        for (auto i : topNode) {
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
    vector<int> result = solution.topView(root);

    // Print the nodes visible from the top view.
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}



// This code is a solution to a problem that involves finding the top view of a binary tree. The top view of a binary tree is defined as the nodes that are visible from the top when looking at the tree from left to right.

// The code starts by checking if the root of the tree is NULL. If it is, an empty vector is returned as there are no nodes in the tree.

// Next, a map called `topNode` is created. This map will store the top view nodes of the tree. The key of the map represents the horizontal distance (HD) of a node from the root, and the value represents the data of the node.

// A queue called `q` is also created. This queue will be used for a breadth-first search (BFS) traversal of the tree.

// The root node is pushed into the queue with a horizontal distance of 0.

// The code then enters a while loop that continues until the queue is empty. In each iteration of the loop, the front element of the queue is removed and stored in a pair called `temp`. The first element of the pair is the node itself, and the second element is the horizontal distance of the node from the root.

// The code then checks if the horizontal distance (`hd`) is already present in the `topNode` map. If it is not present, it means that this is the first node encountered with this horizontal distance, so it is added to the `topNode` map with its data.

// Next, the code checks if the front node has a left child. If it does, the left child is pushed into the queue with a horizontal distance of `hd-1`. This ensures that the left child will have a smaller horizontal distance than its parent.

// Similarly, if the front node has a right child, it is pushed into the queue with a horizontal distance of `hd+1`. This ensures that the right child will have a larger horizontal distance than its parent.

// Once the BFS traversal is complete, the `topNode` map contains all the nodes that are visible from the top view of the tree. The code then iterates over the `topNode` map and adds the values (node data) to the `ans` vector.

// Finally, the `ans` vector is returned, which contains the top view nodes of the binary tree in the order from left to right.