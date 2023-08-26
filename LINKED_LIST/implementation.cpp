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

void deleteNode(Node *&head, int position){
    // deleting first or start node 
    if(position==1){
        Node *temp = head;   
        head = head->next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
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
    deleteNode(head , 1);
    print(head);
    return 0;
}

// This code defines a class called `Node` which represents a node in a linked list. Each node has an integer data value and a pointer to the next node in the list.
// The code also includes several functions for manipulating the linked list:
// 1. `insertAtHead`: This function takes a reference to the head of the linked list and an integer data value. It creates a new node with the given data value and inserts it at the beginning of the list. The new node's `next` pointer is set to the current head, and the head is updated to point to the new node.
// 2. `insertAtTail`: This function takes a reference to the tail of the linked list and an integer data value. It creates a new node with the given data value and inserts it at the end of the list. It does this by iterating through the list starting from the tail until it reaches the last node, and then setting the `next` pointer of the last node to the new node.
// 3. `insertAtPosition`: This function takes a reference to the head and tail of the linked list, an integer data value, and a position. It inserts a new node with the given data value at the specified position in the list. If the position is 1, it calls the `insertAtHead` function to insert the node at the beginning of the list. Otherwise, it iterates through the list starting from the head until it reaches the node before the specified position, and then inserts the new node after that node.
// 4. `deleteNode`: This function takes a reference to the head of the linked list and a position. It deletes the node at the specified position in the list. If the position is 1, it updates the head to point to the second node and frees the memory of the first node. Otherwise, it iterates through the list starting from the head until it reaches the node before the specified position, and then updates the `next` pointer of that node to skip the node at the specified position. It then frees the memory of the node at the specified position.
// 5. `print`: This function takes a pointer to the head of the linked list and prints the data values of all nodes in the list, separated by spaces.
// Overall, this code provides basic operations for creating, inserting, deleting, and printing a linked list.