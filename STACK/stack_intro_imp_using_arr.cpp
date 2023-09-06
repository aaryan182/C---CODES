#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    /*
    // creation of a stack using STL
   stack<int>s;
   // pushing elements in the stack
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   // poping element from the stack
   s.pop();
   cout<<"Printing top element "<<s.top()<<endl;
    if(s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }

    cout<<"size of stack "<<s.size()<<endl;
    */
    return 0;
}

// This code defines a class called `Stack` which represents a stack data structure. A stack is a collection of elements that supports two main operations: `push` and `pop`. 

// The `Stack` class has the following member variables:
// - `arr`: a pointer to an array of integers, which will be used to store the elements of the stack.
// - `size`: an integer representing the maximum size of the stack.
// - `top`: an integer representing the index of the top element in the stack.

// The `Stack` class also has a constructor, which takes an integer parameter `size` and initializes the member variables. It allocates memory for the array `arr` using the `new` keyword and sets the `top` variable to -1, indicating an empty stack.

// The `push` method takes an integer parameter `data` and adds it to the stack. It first checks if there is enough space in the stack to add the element by comparing `size - top` with 1. If there is enough space, it increments the `top` variable and assigns the `data` value to the corresponding index in the `arr` array. If there is not enough space, it prints "Stack overflow".

// The `pop` method removes the top element from the stack. It first checks if the stack is not empty by comparing `top` with 0. If the stack is not empty, it decrements the `top` variable. If the stack is empty, it prints "Stack underflow".

// The `peek` method returns the value of the top element in the stack without removing it. It first checks if the stack is not empty by comparing `top` with 0. If the stack is not empty, it returns the value at the corresponding index in the `arr` array. If the stack is empty, it prints "stack is empty" and returns -1.

// The `isEmpty` method checks if the stack is empty by comparing `top` with -1. If `top` is -1, it means the stack is empty and the method returns `true`. Otherwise, it returns `false`.