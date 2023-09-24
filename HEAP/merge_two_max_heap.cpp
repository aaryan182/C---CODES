#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
        // Step 1: Merge both arrays into one.
        vector<int> ans;
        for (auto i : a)
            ans.push_back(i);
        for (auto i : b)
            ans.push_back(i);

        // Step 2: Build a heap using the merged arrays.
        int size = ans.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(ans, size, i);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> heap1 = {10, 7, 5, 2};
    vector<int> heap2 = {12, 9, 6, 3};

    vector<int> mergedHeap = solution.mergeHeaps(heap1, heap2, heap1.size(), heap2.size());

    cout << "Merged Heap: ";
    for (int num : mergedHeap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


// This code is written in C++ and it includes two functions: `heapify` and `mergeHeaps`.

// The `heapify` function takes in a vector `arr`, its size `n`, and an index `i`. It is used to maintain the heap property in a binary heap. 

// In a binary heap, each parent node is greater than or equal to its children. The `heapify` function compares the value at index `i` with its left and right child nodes. If either of the child nodes is greater than the parent node, the function swaps the parent node with the largest child node. This ensures that the largest element is at the root of the subtree rooted at index `i`. 

// After swapping, the `heapify` function is recursively called on the subtree rooted at the new index `largest`. This process continues until the heap property is maintained for the entire binary heap.

// The `mergeHeaps` function takes in two vectors `a` and `b`, their sizes `n` and `m` respectively. It merges the two vectors into one vector `ans` by appending the elements of `b` to `a`.

// Then, it builds a heap using the merged vector `ans`. It starts from the last non-leaf node (index `size/2 - 1`) and calls the `heapify` function on each node in reverse order. This ensures that the heap property is maintained for the entire binary heap.

// Finally, the function returns the merged and heapified vector `ans`.