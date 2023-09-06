#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }

    // pushing element to stack
    void push(int element)
    {
        Node *t = new Node;
        if (t == NULL)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        t->data = element;
        t->next = top;
        top = t;
        cout << element << " pushed to stack" << endl;
    }

    // popping element from stack
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow" << endl;
            return;
        }
        cout << top->data << " popped from stack" << endl;
        Node *t = top;
        top = top->next;
        delete t;
    }

    // check if stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    if (s.isEmpty())
    {
        cout << "Stack is empty"<<endl;
    }
    else
    {
        cout << "Stack is not empty"<<endl;;
    }

    s.pop();

    return 0;
}

// This code defines a class called `Stack` that represents a stack data structure. A stack is a collection of elements that supports two main operations: push and pop. 

// The `Stack` class has a private member variable called `top`, which is a pointer to the top element of the stack. Initially, the `top` is set to `NULL`, indicating an empty stack.

// The constructor of the `Stack` class initializes the `top` pointer to `NULL`.

// The `push` method takes an integer `element` as input and adds it to the top of the stack. It first creates a new `Node` object `t` using the `new` keyword. If the memory allocation for `t` fails (i.e., `t` is `NULL`), it prints "Stack overflow" and returns. Otherwise, it sets the `data` member of `t` to the input `element`, sets the `next` member of `t` to the current `top` element, and updates the `top` pointer to point to `t`. Finally, it prints the message "element pushed to stack".

// The `pop` method removes the top element from the stack. If the stack is empty (i.e., `top` is `NULL`), it prints "stack underflow" and returns. Otherwise, it prints the value of the top element, updates the `top` pointer to point to the next element in the stack, and deletes the memory allocated for the previous top element.

// The `isEmpty` method checks if the stack is empty by checking if the `top` pointer is `NULL`. It returns `true` if the stack is empty and `false` otherwise.