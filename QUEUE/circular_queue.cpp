#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            // cout<<"Queue is full ";
            return false;
        }
        else if (front == -1) // first element to push
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
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        if (front == -1)
        {
            // cout<<"Queue is empty "<<endl;
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
            front = 0; // to maintain the cyclic nature
        }
        else
        {
            front++;
        }
        return ans;
    }
};

int main()
{
    CircularQueue myCircularQueue(5);

    myCircularQueue.enqueue(1);
    myCircularQueue.enqueue(2);
    myCircularQueue.enqueue(3);
    myCircularQueue.enqueue(4);
    myCircularQueue.enqueue(5);

    if (myCircularQueue.enqueue(6))
    {
        cout << "Enqueued element: 6" << endl;
    }
    else
    {
        cout << "Queue is full. Element 6 couldn't be enqueued." << endl;
    }

    int dequeuedElement;
    while ((dequeuedElement = myCircularQueue.dequeue()) != -1)
    {
        cout << "Dequeued element: " << dequeuedElement << endl;
    }

    if ((dequeuedElement = myCircularQueue.dequeue()) != -1)
    {
        cout << "Dequeued element: " << dequeuedElement << endl;
    }
    else
    {
        cout << "Queue is empty. No element to dequeue." << endl;
    }

    return 0;
}


// This code defines a class called `CircularQueue` which implements a circular queue data structure. A circular queue is a data structure that follows the First-In-First-Out (FIFO) principle, where elements are added to the rear and removed from the front.

// The class has the following private member variables:
// - `arr`: a dynamic array to store the elements of the queue
// - `front`: an integer representing the index of the front element in the array
// - `rear`: an integer representing the index of the rear element in the array
// - `size`: an integer representing the maximum size of the queue

// The class has a constructor that takes an integer `n` as a parameter and initializes the size of the queue. It also initializes the `front` and `rear` indices to -1, indicating an empty queue.

// The class has two public member functions:

// 1. `bool enqueue(int value)`: This function is used to add an element `value` to the rear of the queue. It returns `true` if the element is successfully added to the queue, and `false` otherwise. 

//    The function first checks if the queue is full by checking two conditions:
//    - If `front` is at the beginning of the array and `rear` is at the end of the array (`front == 0` and `rear == size - 1`), or
//    - If `rear` is just before `front` in a circular manner (`rear == (front - 1) % (size - 1)`).
   
//    If either of these conditions is true, it means the queue is full and the function returns `false`.
   
//    If the queue is not full, the function checks if it is the first element to be added (`front == -1`). If so, it sets both `front` and `rear` to 0.
   
//    If the queue is not full and not the first element, the function checks if `rear` is at the end of the array (`rear == size - 1`) and `front` is not at the beginning of the array (`front != 0`). If so, it wraps around the array by setting `rear` to 0.
   
//    If none of the above conditions are true, it increments `rear` by 1.
   
//    Finally, it assigns the `value` to the element at the `rear` index in the array and returns `true`.

// 2. `int dequeue()`: This function is used to remove and return the front element from the queue. It returns -1 if the queue is empty.

//    The function first checks if the queue is empty by checking if `front` is -1. If so, it means the queue is empty and the function returns -1.
   
//    If the queue is not empty, it assigns the value at the `front` index in the array to a variable called `ans`. It also sets the element at the `front` index to -1 to indicate that it is no longer in the queue.
   
//    If there is only one element in the queue (`front == rear`), it means the queue will become empty after removing this element. In this case, it sets both `front` and `rear` to -1.
   
//    If `front` is at the end of the array (`front == size - 1`), it wraps around the array by setting `front` to 0.
   
//    If none of the above conditions are true, it increments `front` by 1.
   
//    Finally, it returns the `ans` variable which contains the value of the removed element.