#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
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

    int k = 17; // The value of k

    // Call the sumK function to find the number of paths with sum equal to k
    int count = solution.sumK(root, k);

    std::cout << "Number of paths with sum equal to " << k << ": " << count << std::endl;

    // Don't forget to free the memory allocated for the tree nodes (you can use a separate function for this)

    return 0;
}



// This code is a solution to find the number of paths in a binary tree that sum up to a given value `k`.

// The code defines a class `Solution` with two functions: `solve` and `sumK`.

// The `solve` function is a recursive function that takes in four parameters: `root` (a pointer to the root of the binary tree), `k` (the target sum), `count` (a reference to an integer variable that keeps track of the number of paths found), and `path` (a vector that stores the current path from the root to the current node).

// The base case of the recursion is when the `root` is `NULL`, which means we have reached the end of a path. In this case, we simply return.

// In the recursive case, we add the current node's value to the `path` vector.

// Then, we recursively call the `solve` function for the left and right child of the current node.

// After the recursive calls, we check if any subpath of the current path sums up to `k`. We iterate through the `path` vector in reverse order and keep track of the running sum. If the running sum equals `k`, we increment the `count` variable.

// Finally, we remove the last element from the `path` vector to backtrack and explore other paths.

// The `sumK` function is the entry point of the solution. It initializes an empty `path` vector and a `count` variable to 0. Then, it calls the `solve` function with the root of the binary tree, `k`, `count`, and `path`. Finally, it returns the `count` variable.

// In summary, this code uses a recursive approach to traverse all paths in a binary tree and checks if any subpath sums up to a given value `k`. It keeps track of the number of paths found using a reference variable `count`.