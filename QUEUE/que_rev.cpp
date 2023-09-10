#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;

        // Push elements from the queue into the stack
        while (!q.empty())
        {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        // Pop elements from the stack and push them back into the queue
        while (!s.empty())
        {
            int element = s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }
};

int main()
{
    Solution solution;

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    queue<int> reversed = solution.rev(q);

    while (!reversed.empty())
    {
        cout << reversed.front() << " ";
        reversed.pop();
    }

    return 0;
}

// This code is a C++ implementation of a function called `rev` that reverses the order of elements in a queue. 

// A queue is a data structure that follows the First-In-First-Out (FIFO) principle, meaning that the element that is inserted first is the first one to be removed. On the other hand, a stack follows the Last-In-First-Out (LIFO) principle, where the last element inserted is the first one to be removed.

// The `rev` function takes a queue `q` as input and returns a new queue with the elements in reverse order. 

// To reverse the order of elements, the function uses a stack `s`. 

// The first step is to push all the elements from the input queue `q` into the stack `s`. This is done using a while loop that continues until the input queue is empty. In each iteration, the front element of the queue is removed using the `pop` function and pushed onto the stack using the `push` function.

// After all the elements have been pushed onto the stack, the function proceeds to pop the elements from the stack and push them back into the input queue. This is done using another while loop that continues until the stack is empty. In each iteration, the top element of the stack is removed using the `pop` function and pushed onto the input queue using the `push` function.

// Finally, the function returns the reversed queue.

// In summary, the `rev` function reverses the order of elements in a queue by using a stack to temporarily store the elements. It first pushes all the elements from the queue onto the stack, and then pops them from the stack and pushes them back into the queue.