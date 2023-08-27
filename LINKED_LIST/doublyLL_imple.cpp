#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data : " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    // empty list
    if (head == NULL)
    {
        head = new Node(d);
        return;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, int d)
{
    if (tail == NULL)
    {
        tail = new Node(d);
        return;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // Insertion at start
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // Insertion at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;

    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle or last node
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        if (prev->next == NULL)
        {
            tail = prev; // Update tail when the last node is deleted
        }
    }
}

// traversing
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

// getting length of the linked list
int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 13);
    print(head);
    insertAtTail(tail, 9);
    print(head);
    insertAtTail(tail, 8);
    print(head);
    insertAtTail(tail, 7);
    print(head);
    insertAtPosition(head, tail, 5, 2);
    print(head);

    deleteNode(head, tail, 8);
    print(head);

    return 0;
}

// This code contains several functions that manipulate a doubly linked list. Let's go through each function and understand how it works.
// The `insertAtHead` function takes a reference to the head of the linked list (`Node *&head`) and an integer value (`int d`). It first checks if the head is `NULL`, which means the list is empty. If it is, it creates a new node with the given value and assigns it to the head. If the list is not empty, it creates a new node with the given value, sets its `next` pointer to the current head, sets the `prev` pointer of the current head to the new node, and finally updates the head to point to the new node.
// The `insertAtTail` function takes a reference to the tail of the linked list (`Node *&tail`) and an integer value (`int d`). It first checks if the tail is `NULL`, which means the list is empty. If it is, it creates a new node with the given value and assigns it to the tail. If the list is not empty, it creates a new node with the given value, sets the `next` pointer of the current tail to the new node, sets the `prev` pointer of the new node to the current tail, and finally updates the tail to point to the new node.
// The `insertAtPosition` function takes a reference to the head of the linked list (`Node *&head`), a reference to the tail of the linked list (`Node *&tail`), an integer value (`int data`), and an integer position (`int position`). It first checks if the position is 1. If it is, it calls the `insertAtHead` function to insert the node at the head. If the position is not 1, it initializes a temporary pointer `temp` to the head of the list and a counter `count` to 1. It then iterates through the list until the counter is less than `position - 1`, updating `temp` and incrementing `count` in each iteration. Once the loop ends, it checks if `temp->next` is `NULL`, which means the position is at the end of the list. If it is, it calls the `insertAtTail` function to insert the node at the tail. If the position is not at the end, it creates a new node with the given value, sets its `next` pointer to `temp->next`, sets the `prev` pointer of `temp->next` to the new node, sets the `next` pointer of `temp` to the new node, and sets the `prev` pointer of the new node to `temp`.
// The `deleteNode` function takes a reference to the head of the linked list (`Node *&head`), a reference to the tail of the linked list (`Node *&tail`), and an integer position (`int position`). It first checks if the position is 1. If it is, it creates a temporary pointer `temp` to the head, updates the `prev` pointer of `temp->next` to `NULL`, updates the head to `temp->next`, updates the `next` pointer of `temp` to `NULL`, and finally deletes `temp`. If the position is not 1, it initializes two temporary pointers `curr` and `prev` to the head and `NULL` respectively, and a counter `count` to 1. It then iterates through the list until the counter is less than `position`, updating `prev` and `curr` in each iteration. Once the loop ends, it updates the `prev` pointer of `curr->next` to `NULL`, updates the `next` pointer of `prev` to `curr->next`, updates the `next` pointer of `curr` to `NULL`, and finally deletes `curr`. If the `next` pointer of `prev` is `NULL`, it means the deleted node was the tail, so it updates the tail to `prev`.
// Overall, these functions provide the basic operations for inserting and deleting nodes in a doubly linked list at the head, tail, and a specific position.