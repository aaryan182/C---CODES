#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *insertIntoBST(Node *&root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data <= root->data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);

    return root;
}

Node* deleteFromBST(Node* root, int val){
    // base case 
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        //1 child
        
        // left child 
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            Node* temp = minVal(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right, temp->data);
            return root;
        }
    }
    else if(val < root->data){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}


int main()
{
    Node *root = NULL;
    cout << "enter data to create bst" << endl;
    takeInput(root);
    cout << "printing the bst" << endl;
    levelOrderTraversal(root);
    cout << endl
         << "printing inorder of bst" << endl;
    inorder(root);
    cout << endl
         << "printing preorder of bst" << endl;
    preOrder(root);
    cout << endl
         << "printing postorder of bst" << endl;
    postOrder(root);

    cout<<endl<<"minimum value of bst is : "<<endl;
    cout<<minVal(root)->data;

    cout<<endl<<"maximum value of bst is : "<<endl;
    cout<<maxVal(root)->data; 

    
    return 0;
}


// This code includes several functions related to binary search trees (BST) and tree traversals. Let's go through each function and understand what it does.

// 1. `levelOrderTraversal(Node *root)`: This function performs a level order traversal of a binary tree. It uses a queue to keep track of the nodes at each level. The function starts by pushing the root node into the queue. Then, it enters a while loop that continues until the queue is empty. Inside the loop, it dequeues a node from the front of the queue and checks if it is NULL. If it is NULL, it means that all nodes at the current level have been processed, so a new line is printed. If the dequeued node is not NULL, its data is printed, and its left and right children (if any) are pushed into the queue. Finally, if the queue is not empty, a NULL node is pushed into the queue to mark the end of the current level.

// 2. `inorder(Node *root)`: This function performs an inorder traversal of a binary tree. It recursively visits the left subtree, prints the data of the current node, and then recursively visits the right subtree. The base case for the recursion is when the root node is NULL.

// 3. `preOrder(Node *root)`: This function performs a preorder traversal of a binary tree. It prints the data of the current node, recursively visits the left subtree, and then recursively visits the right subtree. The base case for the recursion is when the root node is NULL.

// 4. `postOrder(Node *root)`: This function performs a postorder traversal of a binary tree. It recursively visits the left subtree, recursively visits the right subtree, and then prints the data of the current node. The base case for the recursion is when the root node is NULL.

// 5. `insertIntoBST(Node *&root, int data)`: This function inserts a new node with the given data into a binary search tree. It takes a reference to the root node as a parameter. If the root node is NULL, it creates a new node with the given data and assigns it to the root. Otherwise, it compares the data with the data of the current node. If the data is less than or equal to the current node's data, it recursively calls the function on the left subtree. Otherwise, it recursively calls the function on the right subtree. Finally, it returns the root node.

// 6. `takeInput(Node *&root)`: This function takes input from the user and inserts the data into a binary search tree. It takes a reference to the root node as a parameter. It repeatedly reads data from the user until -1 is entered. For each data, it calls the `insertIntoBST` function to insert it into the tree.

// 7. `minVal(Node* root)`: This function finds the minimum value node in a binary search tree. It takes the root node as a parameter and iteratively traverses the left subtree until it reaches the leftmost node, which has the minimum value. It returns the pointer to that node.

// 8. `maxVal(Node* root)`: This function finds the maximum value node in a binary search tree. It takes the root node as a parameter and iteratively traverses the right subtree until it reaches the rightmost node, which has the maximum value. It returns the pointer to that node.

// These functions provide various operations and traversals for binary search trees, allowing us to manipulate and analyze the data stored in the tree.


 
//  FOR DELETION OF NODE IN BST 

// This code is a function that deletes a node with a specific value from a binary search tree (BST). 

// A BST is a binary tree where each node has a value greater than all the values in its left subtree and less than all the values in its right subtree. 

// The function takes two parameters: the root of the BST and the value to be deleted. It returns the root of the modified BST after the deletion.

// The function starts with a base case: if the root is NULL (i.e., the BST is empty), it simply returns the root.

// Next, it checks if the value to be deleted is equal to the value of the current root node. If they are equal, it handles three cases based on the number of children the node has.

// If the node has no children (i.e., both the left and right child pointers are NULL), it simply returns NULL, effectively deleting the node.

// If the node has only one child (either the left or right child pointer is not NULL), it updates the parent node's child pointer to point to the child node and then deletes the current node. It returns the child node as the new root.

// If the node has two children, it finds the minimum value in the right subtree (i.e., the leftmost node in the right subtree) and replaces the value of the current node with the minimum value. It then recursively calls the deleteFromBST function on the right subtree to delete the node with the minimum value. Finally, it returns the root of the modified BST.

// If the value to be deleted is less than the value of the current root node, it recursively calls the deleteFromBST function on the left subtree and updates the left child pointer of the current root node with the returned root.

// If the value to be deleted is greater than the value of the current root node, it recursively calls the deleteFromBST function on the right subtree and updates the right child pointer of the current root node with the returned root.

// Finally, it returns the root of the modified BST.