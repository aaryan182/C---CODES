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
    return 0;
}

// This code defines a class called `Node` which represents a node in a linked list. Each node has an integer data value and a pointer to the next node in the list.
// The `Node` class has a constructor that takes an integer parameter and initializes the data value with the parameter value and sets the next pointer to `NULL`.
// The code also includes two functions: `insertAtHead` and `print`.
// The `insertAtHead` function takes a reference to a pointer to a `Node` object (`head`) and an integer value (`data`). It creates a new `Node` object with the given data value and sets its next pointer to the current head node. Then it updates the head pointer to point to the new node, effectively inserting the new node at the beginning of the linked list.
// The `print` function takes a pointer to a `Node` object (`head`) and prints the data values of all nodes in the linked list. It starts by creating a temporary pointer (`temp`) and setting it to the head node. Then it enters a loop that continues until the `temp` pointer reaches `NULL`. Inside the loop, it prints the data value of the current node and updates the `temp` pointer to point to the next node in the list. Finally, it prints a newline character to separate the output from any subsequent output.
// Overall, this code provides a basic implementation of a linked list data structure with the ability to insert a new node at the beginning of the list and print the contents of the list.