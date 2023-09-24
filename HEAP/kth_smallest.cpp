#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;

        // Step 1: Insert the first k elements into the priority queue.
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // Step 2: Compare each element from k to r with the top element of the priority queue.
        // If the element is smaller, pop the top element and push the current element.
        for (int i = k; i <= r; i++) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // The kth smallest element is at the top of the priority queue.
        int ans = pq.top();
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example usage:
    int arr[] = {12, 3, 1, 9, 15, 7};
    int k = 3; // Find the 3rd smallest element

    int result = solution.kthSmallest(arr, 0, 5, k);

    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}

// This code is a C++ implementation of a function that finds the kth smallest element in an array. The function takes in an array `arr`, the starting index `l`, the ending index `r`, and the value of `k`.

// The function uses a priority queue, which is a data structure that allows efficient insertion and retrieval of the highest priority element. In this case, the priority queue is implemented as a max heap, meaning that the highest priority element is the largest element.

// Here's how the code works:

// 1. First, a priority queue `pq` is created. This will be used to store the k smallest elements.

// 2. The code then enters a loop that inserts the first k elements of the array into the priority queue. This is done by iterating from index 0 to k-1 and pushing each element onto the priority queue using the `push()` function.

// 3. After the first k elements are inserted, the code enters another loop that compares each element from index k to r with the top element of the priority queue. If the current element is smaller than the top element of the priority queue, it means that it is one of the k smallest elements. In this case, the top element is popped from the priority queue using the `pop()` function, and the current element is pushed onto the priority queue using the `push()` function. This ensures that the priority queue always contains the k smallest elements.

// 4. Once the loop is finished, the kth smallest element is at the top of the priority queue. This element is retrieved using the `top()` function and stored in the variable `ans`.

// 5. Finally, the function returns the value of `ans`, which is the kth smallest element in the array.

// Overall, this code efficiently finds the kth smallest element in an array by using a priority queue to keep track of the k smallest elements.