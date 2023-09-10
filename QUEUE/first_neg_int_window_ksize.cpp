#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    for (long long int i = 0; i < N; i++) {
        // Remove elements that are no longer in the current window
        if (!dq.empty() && dq.front() < i - K + 1) {
            dq.pop_front();
        }

        // Add the current element to the deque if it's negative
        if (A[i] < 0) {
            dq.push_back(i);
        }

        // Store the answer for the current window
        if (i >= K - 1) {
            ans.push_back(dq.empty() ? 0 : A[dq.front()]);
        }
    } 
    return ans;
}

int main() {
    // Example usage
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = sizeof(A) / sizeof(A[0]);
    long long int K = 3;

    vector<long long> result = printFirstNegativeInteger(A, N, K);

    cout << "First negative integers in each window of size " << K << ":" << endl;
    for (long long num : result) {
        cout << num << " ";
    }

    return 0;
}

// This code is a function that takes in an array of integers `A`, the size of the array `N`, and a window size `K`. The function returns a vector of integers `ans`.

// The function uses a deque (double-ended queue) data structure to solve the problem. A deque is a data structure that allows insertion and deletion at both ends in constant time.

// The function iterates over the array `A` using a for loop. In each iteration, it performs the following steps:

// 1. It checks if the deque is not empty and if the index at the front of the deque is less than `i - K + 1`. If this condition is true, it means that the element at the front of the deque is no longer in the current window, so it is removed from the deque using the `pop_front()` function.

// 2. It checks if the current element `A[i]` is negative. If it is, it means that it is the first negative element in the current window, so it is added to the deque using the `push_back()` function.

// 3. It checks if the current index `i` is greater than or equal to `K - 1`. If it is, it means that the current window has reached the desired size `K`. In this case, it stores the answer for the current window in the `ans` vector. If the deque is empty, it means that there are no negative elements in the current window, so it stores 0 in the `ans` vector. Otherwise, it stores the value of the first element in the deque (which is the first negative element in the current window) in the `ans` vector.

// After iterating over the entire array, the function returns the `ans` vector.

// In summary, this code finds the first negative integer in each window of size `K` in the given array `A` and returns a vector containing these negative integers.