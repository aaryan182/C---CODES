#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, item);
    st.push(temp);
}

// Function to reverse a stack using recursion
void reverseStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    int item = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, item);
}

int main() {
    stack<int> myStack;
    int n;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter " << n << " elements to push onto the stack:\n";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        myStack.push(num);
    }

    stack<int> reversedStack = myStack; // Create a copy of the original stack
    reverseStack(reversedStack);

    cout << "Stack before reversal:\n";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << "\nReversing the stack...\n";

    cout << "Stack after reversal:\n";
    while (!reversedStack.empty()) {
        cout << reversedStack.top() << " ";
        reversedStack.pop();
    }

    return 0;
}



// This code is a recursive implementation of a function to reverse a stack. 

// The code consists of two functions: `insertAtBottom` and `reverseStack`.

// The `insertAtBottom` function takes a stack and an item as parameters. It checks if the stack is empty. If it is, it simply pushes the item onto the stack and returns. If the stack is not empty, it takes the top element of the stack, removes it using the `pop` function, recursively calls `insertAtBottom` with the same stack and the item, and then pushes the removed element back onto the stack using the `push` function.

// The `reverseStack` function takes a stack as a parameter. It first checks if the stack is empty. If it is, it simply returns. If the stack is not empty, it takes the top element of the stack, removes it using the `pop` function, recursively calls `reverseStack` with the same stack, and then calls `insertAtBottom` with the same stack and the removed element. This effectively reverses the stack.

// By calling the `reverseStack` function with a stack as a parameter, the stack will be reversed in place.