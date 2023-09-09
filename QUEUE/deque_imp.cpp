#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check full or not
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty())
        { // to check queue is empty
            // cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())
        { // to check queue is empty
            // cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1; // to maintain cyclic nature
        }
        else
        { // normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
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
    // Create a Deque with a maximum size of 5
    Deque dq(5);

    // Push elements to the front and rear of the deque
    dq.pushFront(1); // Front: 1, Rear: 1
    dq.pushRear(2);  // Front: 1, Rear: 2
    dq.pushFront(3); // Front: 3, Rear: 2
    dq.pushRear(4);  // Front: 3, Rear: 4
    dq.pushFront(5); // Front: 5, Rear: 4

    // Try pushing to a full deque
    if (dq.pushFront(6))
    {
        std::cout << "Pushed 6 to the front." << std::endl;
    }
    else
    {
        std::cout << "Failed to push 6 to the front. Deque is full." << std::endl;
    }

    // Pop elements from the front and rear of the deque
    int frontValue = dq.popFront(); // Front: 3, Rear: 4, frontValue = 5
    int rearValue = dq.popRear();   // Front: 3, Rear: 2, rearValue = 4

    std::cout << "Front value: " << frontValue << std::endl;
    std::cout << "Rear value: " << rearValue << std::endl;

    // Get the front and rear elements without popping
    int frontElement = dq.getFront();
    int rearElement = dq.getRear();

    std::cout << "Front element: " << frontElement << std::endl;
    std::cout << "Rear element: " << rearElement << std::endl;

    // Check if the deque is empty or full
    if (dq.isEmpty())
    {
        std::cout << "Deque is empty." << std::endl;
    }
    else
    {
        std::cout << "Deque is not empty." << std::endl;
    }

    if (dq.isFull())
    {
        std::cout << "Deque is full." << std::endl;
    }
    else
    {
        std::cout << "Deque is not full." << std::endl;
    }

    return 0;
}


// This code is implementing a deque (double-ended queue) using an array. A deque is a data structure that allows insertion and deletion of elements from both ends.

// The code defines four functions: `pushFront`, `pushRear`, `popFront`, and `popRear`.

// The `pushFront` function takes an integer `x` as input and inserts it at the front of the deque. It first checks if the deque is full by calling the `isFull` function. If the deque is full, it returns `false` to indicate that the insertion was not successful. If the deque is not full, it checks if it is empty by calling the `isEmpty` function. If the deque is empty, it sets both the `front` and `rear` pointers to 0. If the deque is not empty, it checks if the `front` pointer is at the beginning of the array (index 0) and the `rear` pointer is not at the end of the array (index `size - 1`). If this condition is true, it sets the `front` pointer to `size - 1` to wrap around to the end of the array. Otherwise, it decrements the `front` pointer by 1. Finally, it assigns the value `x` to the element at the `front` index of the array and returns `true` to indicate that the insertion was successful.

// The `pushRear` function is similar to the `pushFront` function, but it inserts the element at the rear of the deque. It checks if the deque is full and returns `false` if it is. If the deque is empty, it sets both the `front` and `rear` pointers to 0. If the `rear` pointer is at the end of the array and the `front` pointer is not at the beginning of the array, it sets the `rear` pointer to 0 to wrap around to the beginning of the array. Otherwise, it increments the `rear` pointer by 1. It assigns the value `x` to the element at the `rear` index of the array and returns `true` to indicate that the insertion was successful.

// The `popFront` function removes and returns the element at the front of the deque. If the deque is empty, it returns -1 to indicate that there are no elements to remove. Otherwise, it assigns the value at the `front` index of the array to the variable `ans`. It then sets the element at the `front` index of the array to -1 to indicate that it is empty. If the `front` and `rear` pointers are equal, it means that there was only one element in the deque, so it sets both pointers to -1 to indicate that the deque is now empty. If the `front` pointer is at the end of the array, it sets it to 0 to wrap around to the beginning of the array. Otherwise, it increments the `front` pointer by 1. Finally, it returns the value `ans`.

// The `popRear` function is similar to the `popFront` function, but it removes and returns the element at the rear of the deque. If the deque is empty, it returns -1. Otherwise, it assigns the value at the `rear` index of the array to the variable `ans`. It then sets the element at the `rear` index of the array to -1. If the `front` and `rear` pointers are equal, it sets both pointers to -1. If the `rear` pointer is at the beginning of the array, it sets it to `size - 1` to wrap around to the end of the array. Otherwise, it decrements the `rear` pointer by 1. Finally, it returns the value `ans`.