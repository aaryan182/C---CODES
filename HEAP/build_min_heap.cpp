#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> minHeap = buildMinHeap(arr);

    cout << "Min Heap: ";
    for (int num : minHeap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// This code is implementing the heapify algorithm and using it to build a min heap.

// The `heapify` function takes in a vector `arr`, the size of the heap `n`, and the index `i` of the current node. It first initializes the `smallest` variable to `i`, and calculates the indices of the left and right child nodes. 

// Then, it checks if the left child node exists and if its value is smaller than the value at the current node. If so, it updates the `smallest` variable to the index of the left child node. It does the same check for the right child node.

// After checking both child nodes, if the `smallest` variable is not equal to `i`, it means that one of the child nodes has a smaller value. In this case, it swaps the values of the current node and the smallest child node, and recursively calls `heapify` on the smallest child node to ensure that the heap property is maintained.

// The `buildMinHeap` function takes in a vector `arr` and first calculates the size of the heap `n`. It then iterates over the nodes starting from the last non-leaf node (which is at index `n/2 - 1`) and calls `heapify` on each node. This ensures that the heap property is maintained for all nodes in the heap.

// Finally, it returns the modified `arr` vector, which now represents a min heap.