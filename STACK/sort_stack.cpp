#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& s, int num) {
    if (s.empty() || (!s.empty() && s.top() < num)) {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    // recursive call
    sortedInsert(s, num);
    s.push(n);
}

void sortStack(stack<int>& stack) {
    // base case
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    sortedInsert(stack, num);
}

int main() {
    stack<int> s;

    // Push some integers onto the stack
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    s.push(3);

    cout << "Original Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    // Sort the stack
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    s.push(3);
    sortStack(s);

    cout << "Sorted Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}


// This code is implementing a recursive algorithm to sort a stack of integers in ascending order.

// The `sortedInsert` function is used to insert a number into a sorted stack. It takes two parameters: the stack `s` and the number `num` to be inserted. 

// First, it checks if the stack is empty or if the top element of the stack is less than the number to be inserted. If either of these conditions is true, it simply pushes the number onto the stack and returns.

// If the stack is not empty and the top element is greater than or equal to the number to be inserted, it removes the top element from the stack and stores it in a variable `n`.

// Then, it makes a recursive call to `sortedInsert` with the same stack and the number to be inserted. This recursive call will continue until the base case is reached.

// After the recursive call, it pushes the stored element `n` back onto the stack. This ensures that the number `num` is inserted at the correct position in the sorted stack.

// The `sortStack` function is the main function that sorts the stack using the `sortedInsert` function. It takes a stack as a parameter.

// First, it checks if the stack is empty. If it is, it simply returns.

// If the stack is not empty, it removes the top element from the stack and stores it in a variable `num`.

// Then, it makes a recursive call to `sortStack` with the same stack. This recursive call will continue until the base case is reached.

// After the recursive call, it calls the `sortedInsert` function with the stack and the stored element `num`. This will insert the element `num` at the correct position in the sorted stack.

// Overall, the code uses recursion to sort the stack by repeatedly removing the top element, sorting the remaining stack, and then inserting the removed element back into the sorted stack. This process is repeated until the stack is empty and all elements are sorted in ascending order.