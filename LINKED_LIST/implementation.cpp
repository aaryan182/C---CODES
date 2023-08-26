#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data : "<<value<<endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    Node *temp1 = tail;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void insertAtPosition(Node *&head,Node *&tail, int data, int position)
{
    //insertion at start
    if(position==1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // insertion at last 
    if (tail->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node *&head,Node *&tail, int position){
    // deleting first or start node 
    if(position==1){
        Node *temp = head;   
        head = head->next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
        if (head == nullptr) {
            tail = nullptr; // List is empty, update tail accordingly
        }
    }
    else
    {
        // deleting any middle or last node
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        if (prev->next == NULL) {
            tail = prev; // Update tail when the last node is deleted
        }
    }
    
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // creating new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    //    print(head);
    //    insertAtHead(head, 20);
    //    print(head);
    //    insertAtHead(head, 30);
    //    print(head);
    print(tail);
    insertAtTail(tail, 20);
    print(tail);
    insertAtTail(tail, 30);
    print(tail);
    insertAtPosition(head ,tail, 25, 3);
    print(tail);
    deleteNode(head ,tail, 1);
    print(head);
    return 0;
}

// This code defines a class called `Node` which represents a node in a linked list. Each node has an integer data value and a pointer to the next node in the list.
// 1. `insertAtHead(Node *&head, int data)`: This function inserts a new node with the given data at the beginning of the linked list. It takes a reference to the head pointer and the data as parameters. 
//    - It creates a new node `temp` with the given data.
//    - It sets the `next` pointer of `temp` to the current head node.
//    - It updates the head pointer to point to the new node `temp`.
// 2. `insertAtTail(Node *&tail, int data)`: This function inserts a new node with the given data at the end of the linked list. It takes a reference to the tail pointer and the data as parameters.
//    - It creates a new node `temp` with the given data.
//    - It initializes a temporary pointer `temp1` to the tail node.
//    - It iterates through the linked list until it reaches the last node (i.e., `temp1->next` is `NULL`).
//    - It sets the `next` pointer of the last node to the new node `temp`.
// 3. `insertAtPosition(Node *&head, Node *&tail, int data, int position)`: This function inserts a new node with the given data at the specified position in the linked list. It takes references to the head and tail pointers, the data, and the position as parameters.
//    - If the position is 1, it calls the `insertAtHead` function to insert the node at the beginning of the linked list and returns.
//    - Otherwise, it creates a new node `nodeToInsert` with the given data.
//    - It initializes a temporary pointer `temp` to the head node.
//    - It iterates through the linked list until it reaches the node before the specified position.
//    - If the tail node's `next` pointer is `NULL`, it calls the `insertAtTail` function to insert the node at the end of the linked list and returns.
//    - It updates the `next` pointer of `nodeToInsert` to point to the node at the specified position.
//    - It updates the `next` pointer of the node before the specified position to point to `nodeToInsert`.
// 4. `deleteNode(Node *&head, Node *&tail, int position)`: This function deletes the node at the specified position in the linked list. It takes references to the head and tail pointers, and the position as parameters.
//    - If the position is 1, it deletes the first node by updating the head pointer and freeing the memory.
//    - Otherwise, it initializes two temporary pointers `curr` and `prev` to the head node and `NULL`, respectively.
//    - It iterates through the linked list until it reaches the node at the specified position.
//    - It updates the `next` pointer of the node before the specified position to point to the node after the specified position.
//    - It sets the `next` pointer of the node at the specified position to `NULL`.
//    - It frees the memory occupied by the node at the specified position.
//    - If the `next` pointer of the node before the specified position is `NULL`, it updates the tail pointer to point to the node before the deleted node.
// 5. `print(Node *head)`: This function prints the data of each node in the linked list. It takes the head pointer as a parameter.
//    - It initializes a temporary pointer `temp` to the head node.
//    - It iterates through the linked list until it reaches the end (i.e., `temp` is `NULL`).
//    - It prints the data of the current node.
//    - It updates `temp` to point to the next node.
// These functions can be used to perform various operations on a linked list, such as inserting nodes at the head, tail, or a specific position, deleting nodes at a specific position, and printing the linked list.