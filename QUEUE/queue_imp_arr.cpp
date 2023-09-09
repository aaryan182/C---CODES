#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int size, qfront, rear;
public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (qfront == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        if (rear == size)
            cout << "Queue is full " << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    // Create an instance of the Queue class
    Queue myQueue;

    // Enqueue some elements
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    // Check if the queue is empty
    if (myQueue.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    // Get the front element
    int frontElement = myQueue.front();
    if (frontElement != -1)
    {
        cout << "Front element: " << frontElement << endl;
    }
    else
    {
        cout << "Queue is empty, no front element." << endl;
    }

    // Dequeue elements
    int dequeuedElement = myQueue.dequeue();
    if (dequeuedElement != -1)
    {
        cout << "Dequeued element: " << dequeuedElement << endl;
    }
    else
    {
        cout << "Queue is empty, nothing to dequeue." << endl;
    }

    // Check if the queue is empty again
    if (myQueue.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}

// This code defines a class called `Queue` which represents a queue data structure. A queue is a collection of elements that supports two main operations: enqueue, which adds an element to the back of the queue, and dequeue, which removes and returns the element at the front of the queue.

// The `Queue` class has the following private member variables:
// - `arr`: a dynamic array of integers to store the elements of the queue
// - `size`: the maximum size of the queue
// - `qfront`: the index of the front element in the queue
// - `rear`: the index of the next available position at the back of the queue

// The class also has a public constructor `Queue()` which initializes the member variables. It sets the size to 100001, creates a new dynamic array of integers with the specified size, and sets both `qfront` and `rear` to 0.

// The class provides the following public member functions:

// - `bool isEmpty()`: This function checks if the queue is empty. It compares the indices of the front and rear elements. If they are equal, it means the queue is empty and the function returns `true`, otherwise it returns `false`.

// - `void enqueue(int data)`: This function adds an element to the back of the queue. It first checks if the rear index is equal to the size of the queue, which means the queue is full. If it is full, it prints a message indicating that the queue is full. Otherwise, it assigns the given data to the element at the rear index of the array, and increments the rear index.

// - `int dequeue()`: This function removes and returns the element at the front of the queue. It first checks if the front index is equal to the rear index, which means the queue is empty. If it is empty, it returns -1 to indicate an error. Otherwise, it assigns the value of the element at the front index to a variable called `ans`, sets the element at the front index to -1 (to mark it as empty), increments the front index, and checks if the front index is equal to the rear index. If they are equal, it means the queue is now empty, so it resets both the front and rear indices to 0. Finally, it returns the value of `ans`.

// - `int front()`: This function returns the element at the front of the queue without removing it. It first checks if the front index is equal to the rear index, which means the queue is empty. If it is empty, it returns -1 to indicate an error. Otherwise, it returns the value of the element at the front index.

// Overall, this code implements a basic queue data structure using a dynamic array. It provides functions to check if the queue is empty, add elements to the back of the queue, remove and return elements from the front of the queue, and get the element at the front of the queue without removing it.
