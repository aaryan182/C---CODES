#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        // atleast a empty space is present
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 <= size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int size = 10; // Size of the array

    TwoStack ts(size); // Create an instance of TwoStack

    // Push elements into stack 1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // Push elements into stack 2
    ts.push2(20);
    ts.push2(25);
    ts.push2(30);

    // Pop elements from stack 1
    int popped1 = ts.pop1();
    if (popped1 != -1) {
        cout << "Popped from stack 1: " << popped1 << endl;
    } else {
        cout << "Stack 1 is empty." << endl;
    }

    // Pop elements from stack 2
    int popped2 = ts.pop2();
    if (popped2 != -1) {
        cout << "Popped from stack 2: " << popped2 << endl;
    } else {
        cout << "Stack 2 is empty." << endl;
    }

    return 0;
}


// This code defines a class called `TwoStack` that represents two stacks implemented using a single array. 

// The class has the following private member variables:
// - `arr`: a pointer to an integer array that will store the elements of the two stacks.
// - `top1`: an integer representing the top index of the first stack.
// - `top2`: an integer representing the top index of the second stack.
// - `size`: an integer representing the size of the array.

// The class also has a public constructor that takes an integer `s` as a parameter and initializes the size of the array. It also initializes `top1` to -1 (indicating an empty stack) and `top2` to `s` (indicating an empty stack).

// The class provides the following public member functions:

// - `push1(int num)`: This function is used to push an element `num` into the first stack. It first checks if there is at least one empty space between `top1` and `top2` (i.e., `top2 - top1 > 1`). If there is, it increments `top1` and assigns `num` to `arr[top1]`.

// - `push2(int num)`: This function is used to push an element `num` into the second stack. It also checks if there is at least one empty space between `top1` and `top2`. If there is, it decrements `top2` and assigns `num` to `arr[top2]`.

// - `pop1()`: This function is used to pop an element from the first stack and return the popped element. It first checks if `top1` is greater than or equal to 0 (indicating that the first stack is not empty). If it is, it assigns the value at `arr[top1]` to a variable `ans`, decrements `top1`, and returns `ans`. If the first stack is empty, it returns -1.

// - `pop2()`: This function is used to pop an element from the second stack and return the popped element. It checks if `top2` is less than or equal to `size` (indicating that the second stack is not empty). If it is, it assigns the value at `arr[top2]` to a variable `ans`, increments `top2`, and returns `ans`. If the second stack is empty, it returns -1.

// Overall, this code allows you to push elements into two separate stacks and pop elements from them independently. The stacks are implemented using a single array, and the top indices of the stacks are maintained separately.