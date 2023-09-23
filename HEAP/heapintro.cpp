#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        // step 1: put last element into first index
        arr[1] = arr[size];
        // step 2: remove last element
        size--;

        // step 3: take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
     int size = n;
     while(size > 1){
         swap(arr[size], arr[1]);
         size--;
         heapify(arr, size, 1);
     }
}


int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    // heap creation
    for(int i = n/2; i> 0;i--){
        heapify(arr, n, i);
    }
    cout<<"printing the array now "<<endl;
    for(int i =1 ; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<< endl;

    // heap sort
    heapSort(arr,n);
    cout<<"printing the sorted array now "<<endl;
    for(int i =1 ; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"using Priority Queue"<<endl;
    // maxheap 
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"element at top "<<pq.top()<<endl;
    pq.pop();
    cout<<"element at top "<<pq.top()<<endl;
    cout<<"size of heap "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"heap is empty"<<endl;
    }
    else{
        cout<<"heap is not empty"<<endl;
    }




    // min heap 
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"element at top "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at top "<<minheap.top()<<endl;
    cout<<"size of heap "<<minheap.size()<<endl;
    if(minheap.empty()){
        cout<<" min heap is empty"<<endl;
    }
    else{
        cout<<" min heap is not empty"<<endl;
    }
    return 0;
}



// This code defines a class called `Heap` which represents a binary heap data structure. A binary heap is a complete binary tree where the value of each node is greater than or equal to the values of its children.

// The `Heap` class has three member variables: `arr`, `size`, and a constructor. 

// - `arr` is an array of integers that represents the heap.
// - `size` is an integer that represents the number of elements in the heap.
// - The constructor initializes the `size` variable to 0 and sets the first element of the `arr` array to -1.

// The `Heap` class also has three member functions: `insert`, `print`, and `deleteFromHeap`.

// - The `insert` function takes an integer value as input and inserts it into the heap. It first increments the `size` variable and assigns the value to the `arr` array at the index `size`. Then, it compares the value with its parent node and swaps them if necessary to maintain the heap property. This process continues until the value is in its correct position in the heap.
// - The `print` function prints all the elements in the heap in the order they appear in the `arr` array.
// - The `deleteFromHeap` function removes the root node from the heap. It first checks if the heap is empty and returns if it is. Then, it replaces the root node with the last element in the heap and removes the last element. After that, it compares the new root node with its children and swaps them if necessary to maintain the heap property. This process continues until the root node is in its correct position in the heap.



// This code implements the heap sort algorithm, which is a comparison-based sorting algorithm. 

// The `heapify` function is used to build a max heap from an array. A max heap is a complete binary tree where the value of each node is greater than or equal to the values of its children. The function takes three parameters: the array `arr`, the size of the heap `n`, and the index `i` of the current node being considered.

// Inside the `heapify` function, three variables are initialized: `largest` is set to the index `i`, `left` is set to the index of the left child of `i`, and `right` is set to the index of the right child of `i`.

// The function then checks if the left child exists (`left <= n`) and if its value is greater than the value of the current largest node (`arr[largest] < arr[left]`). If both conditions are true, the value of `largest` is updated to the index of the left child.

// Next, the function checks if the right child exists (`right <= n`) and if its value is greater than the value of the current largest node. If both conditions are true, the value of `largest` is updated to the index of the right child.

// After checking both children, the function checks if the value of `largest` has changed. If it has, it means that one of the children had a greater value than the current node, so a swap is performed between the current node and the largest child. Then, the `heapify` function is called recursively on the new position of the current node (`largest`).

// The `heapSort` function is the main function that performs the heap sort algorithm. It takes two parameters: the array `arr` and the size of the array `n`.

// Inside the `heapSort` function, a variable `size` is initialized to the value of `n`. The algorithm works by repeatedly swapping the root node (which is always the maximum value in a max heap) with the last node in the heap, reducing the size of the heap by one, and then calling `heapify` on the new root node to restore the max heap property.

// The `while` loop continues until the size of the heap is greater than 1. In each iteration, the root node is swapped with the last node (`swap(arr[size], arr[1])`), the size of the heap is decreased by one (`size--`), and `heapify` is called on the new root node (`heapify(arr, size, 1)`).

// After the `while` loop finishes, the array `arr` is sorted in ascending order.