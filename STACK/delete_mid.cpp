#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, size);
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, count, N);
}

int main()
{
    stack<int> inputStack;
    int N;

    cout << "Enter the size of the stack: ";
    cin >> N;

    cout << "Enter the elements of the stack: ";
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        inputStack.push(num);
    }


    deleteMiddle(inputStack, N);

    cout << "Updated stack: ";
    while (!inputStack.empty())
    {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }

    return 0;
}



// The `solve` function takes in a reference to a stack of integers (`inputStack`), an integer `count`, and an integer `size`. It is a recursive function that aims to delete the middle element(s) from the stack.

// The base case of the recursion is when `count` is equal to `size / 2`. In other words, when the count reaches half of the size of the stack. In this case, the function simply pops the top element from the stack and returns.

// If the base case is not met, the function continues with the following steps:

// 1. It retrieves the top element of the stack using the `top` function and assigns it to the variable `num`.
// 2. It then pops the top element from the stack using the `pop` function.
// 3. It recursively calls itself with the updated `count` (incremented by 1) and the same `size`.
// 4. After the recursive call, it pushes the value of `num` back into the stack using the `push` function.

// The `deleteMiddle` function takes in a reference to a stack of integers (`inputStack`) and an integer `N`. It initializes a variable `count` to 0 and then calls the `solve` function with the `inputStack`, `count`, and `N` as arguments.

// In summary, the purpose of this code is to delete the middle element(s) from a stack of integers. It achieves this by recursively popping the top element, calling itself with an incremented count, and then pushing the popped element back into the stack. The `deleteMiddle` function serves as a wrapper function to initiate the recursive process.