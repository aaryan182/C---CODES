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

class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node* r1, Node* r2)
    {
        // Base case
        if (r1 == NULL && r2 == NULL) {
            return true;
        }

        if (r1 == NULL || r2 == NULL) {
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);

        bool value = r1->data == r2->data;

        return left && right && value;
    }
};

int main() {
    // Creating two identical binary trees
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    Solution obj;
    bool identical = obj.isIdentical(root1, root2);

    if (identical) {
        cout << "The two binary trees are identical." << endl;
    } else {
        cout << "The two binary trees are not identical." << endl;
    }

    return 0;
}


// This code defines a binary tree structure using a struct called Node. Each Node has an integer data value and pointers to its left and right child nodes.

// The class Solution contains a function called isIdentical, which takes in two Node pointers r1 and r2 as parameters. This function checks if the two trees rooted at r1 and r2 are identical.

// The function starts with a base case, checking if both r1 and r2 are NULL (i.e., empty trees). If they are both NULL, it returns true, indicating that the trees are identical.

// If either r1 or r2 is NULL while the other is not, it means that the trees have different structures and cannot be identical. In this case, the function returns false.

// If neither r1 nor r2 is NULL, the function recursively calls itself to check if the left subtrees and right subtrees of r1 and r2 are identical. The results of these recursive calls are stored in the variables left and right, respectively.

// The function also checks if the data values of the current nodes r1 and r2 are equal. If they are equal, the variable value is set to true; otherwise, it is set to false.

// Finally, the function returns the logical AND of left, right, and value. This means that for the trees to be identical, both the left and right subtrees must be identical, and the data values of the current nodes must be equal.