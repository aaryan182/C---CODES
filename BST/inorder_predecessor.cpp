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

Node *findInOrderPredecessor(Node *root, Node *target)
{
    Node *predecessor = nullptr;

    while (root)
    {
        if (target->data <= root->data)
        {
            root = root->left;
        }
        else
        {
            predecessor = root;
            root = root->right;
        }
    }

    return predecessor;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);


    int targetValue = 80; 

    Node *target = nullptr;
    Node *current = root;

    // Find the target node based on its value
    while (current)
    {
        if (targetValue == current->data)
        {
            target = current;
            break;
        }
        else if (targetValue < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (target)
    {
        Node *predecessor = findInOrderPredecessor(root, target);
        if (predecessor)
        {
            cout << "In-order predecessor of " << targetValue << " is: " << predecessor->data << endl;
        }
        else
        {
            cout << targetValue << " does not have an in-order predecessor." << endl;
        }
    }
    else
    {
        cout << "Target value " << targetValue << " not found in the BST." << endl;
    }

    return 0;
}
