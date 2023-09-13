
// https://www.codingninjas.com/studio/problems/count-leaf-nodes_893055

void inorder(BinaryTreeNode<int> *root, int &count)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left,count);
    // leaf node 
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inorder(root->right,count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    inorder(root, count);
    return count;
}



// The `inorder` function takes in a pointer to a `BinaryTreeNode` object and a reference to an integer variable `count`. It is a recursive function that performs an inorder traversal of the binary tree.

// In the `inorder` function, there is a base case that checks if the current node is NULL. If it is, the function simply returns and does nothing.

// If the current node is not NULL, the function recursively calls itself on the left child of the current node. This is done to traverse the left subtree of the current node.

// After traversing the left subtree, the function checks if the current node is a leaf node. A leaf node is a node that does not have any children (i.e., both the left and right child pointers are NULL). If the current node is a leaf node, the `count` variable is incremented by 1.

// Finally, the function recursively calls itself on the right child of the current node. This is done to traverse the right subtree of the current node.

// The `noOfLeafNodes` function takes in a pointer to a `BinaryTreeNode` object `root` and returns the number of leaf nodes in the binary tree. It initializes a variable `count` to 0 and then calls the `inorder` function with the `root` and `count` as arguments.

// After the `inorder` function is called, the `count` variable will contain the number of leaf nodes in the binary tree. This value is then returned by the `noOfLeafNodes` function.