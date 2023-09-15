#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> diagonal(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // Traverse the current diagonal.
        while (current) {
            result.push_back(current->data);

            if (current->left) {
                q.push(current->left);
            }

            current = current->right;
        }
    }

    return result;
}

int main() {
    // Create a sample Binary Tree for testing.
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    vector<int> result = diagonal(root);

    cout << "Diagonal Traversal of Binary Tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}


// This code is a function that takes a binary tree as input and returns a vector of integers representing the diagonal traversal of the tree.

// First, the function checks if the root of the tree is null. If it is, an empty vector is returned.

// If the root is not null, a queue is created to store the nodes of the tree. The root node is pushed into the queue.

// Then, a while loop is used to process each node in the queue. In each iteration of the loop, the front node of the queue is removed and assigned to the variable "current".

// Inside the loop, another while loop is used to traverse the current diagonal. This loop continues until the "current" node becomes null.

// In each iteration of the inner loop, the data of the "current" node is added to the result vector. Then, if the "current" node has a left child, it is pushed into the queue. Finally, the "current" node is updated to its right child.

// After the inner loop finishes, the outer loop continues until the queue becomes empty. This ensures that all nodes of the tree are processed.

// Finally, the result vector is returned.

// In summary, this code performs a diagonal traversal of a binary tree using a queue to store the nodes. It starts from the root node and traverses each diagonal by moving to the right child and adding the left child to the queue if it exists. The result is a vector of integers representing the diagonal traversal of the tree.