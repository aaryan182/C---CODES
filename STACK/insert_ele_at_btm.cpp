// INSERT AN ELEMENT AT ITS BOTTOM IN A GIVEN STACK

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    // recursive call
    solve(s, x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

int main()
{
    stack<int> myStack;
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);

    int x = 4;
    myStack = pushAtBottom(myStack, x);

    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}



// The `solve` function takes a reference to a stack of integers (`s`) and an integer (`x`) as parameters. It checks if the stack is empty. If it is, it simply pushes the integer `x` onto the stack and returns.

// If the stack is not empty, the function retrieves the top element of the stack using the `top` function and stores it in a variable called `num`. It then removes the top element from the stack using the `pop` function.

// After that, the `solve` function makes a recursive call to itself with the same stack (`s`) and the integer `x`. This recursive call will continue until the stack becomes empty.

// Once the recursive call returns, the function pushes the previously retrieved element (`num`) back onto the stack using the `push` function.

// The `pushAtBottom` function takes a reference to a stack of integers (`myStack`) and an integer (`x`) as parameters. It calls the `solve` function with the stack and integer as arguments. Finally, it returns the modified stack.

// In summary, the `solve` function recursively pushes an integer to the bottom of a stack by temporarily removing the top elements and then pushing them back after the recursive call. The `pushAtBottom` function simply calls `solve` and returns the modified stack.