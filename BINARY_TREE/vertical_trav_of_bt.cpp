#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> verticalOrder(Node *root)
{
    // Create a map to store nodes based on their horizontal distance (hd)
    // and level (lvl).
    map<int, map<int, vector<int>>> nodes;

    // Create a queue for level-order traversal.
    queue<pair<Node*, pair<int, int>>> q;

    // Create a vector to store the final result.
    vector<int> ans;

    // Check if the root node is NULL, if so, return an empty ans.
    if (root == NULL)
        return ans;

    // Push the root node into the queue with hd = 0 and lvl = 0.
    q.push(make_pair(root, make_pair(0, 0)));

    // Start the level-order traversal.
    while (!q.empty()) {
        // Dequeue a node from the front of the queue.
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        // Extract the front node, hd, and lvl.
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        // Insert the front node's value into the nodes map
        // at the corresponding hd and lvl.
        nodes[hd][lvl].push_back(frontNode->data);

        // If the front node has a left child, enqueue it with
        // a new hd (hd-1) and an increased lvl (lvl+1).
        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        // If the front node has a right child, enqueue it with
        // a new hd (hd+1) and an increased lvl (lvl+1).
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }

    // Iterate through the nodes map to extract values in vertical order.
    for (auto i : nodes) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                ans.push_back(k);
            }
        }
    }

    // Return the ans vector containing the vertical order traversal.
    return ans;
}

// Call the function with the root of the example tree.
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = verticalOrder(root);

    // Printing the result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}


// This code is a C++ implementation of a function that finds the vertical order traversal of a binary tree. 

// The function takes a pointer to the root of the binary tree as input and returns a vector of integers representing the vertical order traversal.

// The function uses a map called "nodes" to store the nodes of the binary tree based on their horizontal distance (hd) and level (lvl). The map is defined as `map<int, map<int,vector<int> > > nodes;`. 

// The function also uses a queue called "q" to perform a level order traversal of the binary tree. The queue is defined as `queue<pair<Node* , pair<int,int> > > q;`. Each element in the queue is a pair consisting of a node pointer and a pair of integers representing the horizontal distance and level of the node.

// The function starts by checking if the root is NULL. If it is, an empty vector is returned.

// If the root is not NULL, it is pushed into the queue with a horizontal distance of 0 and level of 0.

// The function then enters a while loop that continues until the queue is empty. In each iteration of the loop, the front element of the queue is removed and its node pointer, horizontal distance, and level are extracted.

// The data of the front node is then pushed into the "nodes" map at the corresponding horizontal distance and level.

// If the front node has a left child, a pair consisting of the left child and the updated horizontal distance and level is pushed into the queue.

// If the front node has a right child, a pair consisting of the right child and the updated horizontal distance and level is pushed into the queue.

// After the while loop, the "nodes" map is traversed using nested for-each loops. The outer loop iterates over the horizontal distances, the middle loop iterates over the levels, and the inner loop iterates over the nodes at each horizontal distance and level. The data of each node is pushed into the "ans" vector.

// Finally, the "ans" vector is returned as the result of the function.