// reverse level order traveral

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void reverseLevelOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    stack<TreeNode *> s;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        s.push(current);

        if (current->right)
            q.push(current->right);
        if (current->left)
            q.push(current->left);
    }

    // Print the elements in reverse order
    while (!s.empty())
    {
        TreeNode *node = s.top();
        cout << node->data << " ";
        s.pop();
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Reverse Level Order Traversal: ";
    reverseLevelOrderTraversal(root);
    return 0;
}



// This code is for performing a reverse level order traversal of a binary tree. 

// First, we check if the root of the tree is null. If it is, we simply return and exit the function.

// Next, we create two data structures - a queue and a stack. The queue will be used to store the nodes of the tree in a level order manner, and the stack will be used to reverse the order of the nodes.

// We push the root node into the queue.

// Then, we enter a while loop that continues until the queue is empty. Inside the loop, we do the following:

// 1. Get the front element of the queue and remove it from the queue.
// 2. Push the current element into the stack.
// 3. If the current element has a right child, we push it into the queue.
// 4. If the current element has a left child, we push it into the queue.

// After the while loop ends, we have all the nodes of the tree stored in the stack in reverse level order.

// Finally, we enter another while loop that continues until the stack is empty. Inside this loop, we do the following:

// 1. Get the top element of the stack.
// 2. Print the data of the node.
// 3. Pop the top element from the stack.

// This loop will print the elements of the tree in reverse level order.