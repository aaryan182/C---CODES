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

Node *buildTree(Node *root)
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    root = new Node(d);
    cout << "enter data for inserting in left of " << d << endl;
    root->left = buildTree(root->left);
    cout << "enter data for inserting in right of" << d << endl;
    root->right = buildTree(root->right);
    return root;
}

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

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;

    /*
    // creating a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    // level order
    cout << "Printing the level order traversal output is: " << endl;
    levelOrderTraversal(root);

    cout << endl
         << "inorder traversal is : " << endl;
    inorder(root);
    cout << endl
         << "preorder traversal is : " << endl;
    preOrder(root);
    cout << endl
         << "postOrder traversal is : " << endl;
    postOrder(root);
    */

   buildFromLevelOrder(root);
   levelOrderTraversal(root);
//    1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    return 0;
}



// Node *buildTree(Node *root):  This code is a recursive function that builds a binary tree.

// The function takes a pointer to a Node as input, which represents the root of the current subtree. It prompts the user to enter a value for the current node, and reads it from the input using `cin`.

// If the value entered is -1, it means that there are no more nodes to be inserted in the current subtree, so the function returns `NULL` to indicate the end of the subtree.

// If the value entered is not -1, it creates a new Node with the entered value and assigns it to the `root` pointer. Then, it prompts the user to enter data for the left child of the current node and recursively calls the `buildTree` function to build the left subtree. Similarly, it prompts the user to enter data for the right child of the current node and recursively calls the `buildTree` function to build the right subtree.

// Finally, it returns the `root` pointer, which represents the root of the current subtree.






// void levelOrderTraversal(Node *root):  This code is implementing a level order traversal algorithm for a binary tree.

// The function `levelOrderTraversal` takes a pointer to the root node of the binary tree as input.

// It uses a queue data structure to keep track of the nodes that need to be visited.

// Initially, the root node is pushed into the queue.

// Then, a NULL marker is pushed into the queue to indicate the end of a level.

// The code enters a while loop that continues until the queue is empty.

// Inside the loop, the first node in the queue is removed and stored in the `temp` variable.

// If `temp` is NULL, it means that the end of a level has been reached. In this case, a new line is printed to separate the levels.

// If the queue is not empty, another NULL marker is pushed into the queue to indicate the end of the next level.

// If `temp` is not NULL, it means that a valid node has been dequeued. In this case, the data of the node is printed, followed by a space.

// If the node has a left child, it is pushed into the queue.

// If the node has a right child, it is also pushed into the queue.

// This process continues until all nodes in the binary tree have been visited.







// This code defines three functions: `inorder`, `preOrder`, and `postOrder`. Each function takes a pointer to a `Node` as its parameter.

// The `inorder` function performs an inorder traversal of a binary tree. It first checks if the `root` is `NULL`, which is the base case for the recursion. If the `root` is `NULL`, it means that there are no more nodes to process, so the function simply returns. Otherwise, it recursively calls `inorder` on the left subtree, then prints the data of the `root` node, and finally recursively calls `inorder` on the right subtree.

// The `preOrder` function performs a preorder traversal of a binary tree. It also checks if the `root` is `NULL` as the base case. If the `root` is `NULL`, it returns. Otherwise, it first prints the data of the `root` node, then recursively calls `preOrder` on the left subtree, and finally recursively calls `preOrder` on the right subtree.

// The `postOrder` function performs a postorder traversal of a binary tree. It follows the same structure as the other two functions, checking if the `root` is `NULL` as the base case. If the `root` is `NULL`, it returns. Otherwise, it first recursively calls `postOrder` on the left subtree, then recursively calls `postOrder` on the right subtree, and finally prints the data of the `root` node.

// In summary, these three functions traverse a binary tree in different orders: inorder, preorder, and postorder. Each function recursively calls itself on the left and right subtrees, and performs some operation (printing the data of the `root` node) at different points in the recursion.





// This code is a function called `buildFromLevelOrder` that builds a binary tree from level order traversal. 

// Here's how it works:

// 1. The function starts by creating an empty queue `q` and asks the user to enter the data for the root node.
// 2. It reads the input from the user and creates a new node with the entered data. This node becomes the root of the binary tree.
// 3. The root node is then pushed into the queue `q`.
// 4. The function enters a while loop that continues until the queue `q` is empty.
// 5. Inside the loop, the function takes the front element of the queue `q` and assigns it to a temporary node pointer `temp`.
// 6. The front element is then removed from the queue using the `pop` function.
// 7. The function asks the user to enter the data for the left child of the current node `temp`.
// 8. It reads the input from the user and checks if the entered data is not equal to -1.
// 9. If the entered data is not -1, it creates a new node with the entered data and assigns it as the left child of the current node `temp`.
// 10. The newly created left child node is then pushed into the queue `q`.
// 11. The function asks the user to enter the data for the right child of the current node `temp`.
// 12. It reads the input from the user and checks if the entered data is not equal to -1.
// 13. If the entered data is not -1, it creates a new node with the entered data and assigns it as the right child of the current node `temp`.
// 14. The newly created right child node is then pushed into the queue `q`.
// 15. The loop continues until all nodes in the level order traversal are processed.
// 16. Once the loop ends, the binary tree is successfully built from the level order traversal.