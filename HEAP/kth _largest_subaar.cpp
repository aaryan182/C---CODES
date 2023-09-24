#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (minHeap.size() < k) {
                minHeap.push(sum);
            } else {
                if (sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

int main() {
    // Example usage:
    vector<int> arr = {10, -5, 4, 3, -2, 0, 12};
    int k = 3;

    int kthLargestSubarraySum = getKthLargest(arr, k);

    cout << "The " << k << "th largest subarray sum is: " << kthLargestSubarraySum << endl;

    return 0;
}


// This code is a function that takes in a vector of integers `arr` and an integer `k`, and returns the `k`th largest sum of consecutive elements in the vector.

// The function uses a priority queue, specifically a min heap, to keep track of the `k` largest sums encountered so far. The min heap is implemented using the `priority_queue` class in C++.

// The function starts by initializing the min heap. The `priority_queue` constructor takes three arguments: the data type of the elements (`int`), the container type (`vector<int>`), and the comparison function (`greater<int>`). In this case, `greater<int>` is used as the comparison function to create a min heap.

// Next, the function calculates the size of the input vector `arr` and stores it in the variable `n`.

// The function then enters a nested loop. The outer loop iterates over each element in the vector `arr`, starting from the first element and ending at the last element. The inner loop iterates over the elements in `arr` starting from the current element of the outer loop and ending at the last element.

// Inside the inner loop, the function calculates the sum of the elements from the current element to the end of the vector and stores it in the variable `sum`.

// The function then checks if the size of the min heap is less than `k`. If it is, it means that the min heap has not yet reached its maximum capacity of `k` elements, so the current sum is pushed onto the min heap using the `push` function.

// If the size of the min heap is equal to `k`, it means that the min heap is already full. In this case, the function compares the current sum with the smallest element in the min heap, which is the top element. If the current sum is greater than the top element, it means that the current sum is one of the `k` largest sums encountered so far. Therefore, the top element is removed from the min heap using the `pop` function, and the current sum is pushed onto the min heap using the `push` function.

// After the inner loop finishes, the outer loop moves on to the next element in the vector `arr`, and the process is repeated.

// Finally, the function returns the smallest element in the min heap, which is the `k`th largest sum of consecutive elements in the vector `arr`.