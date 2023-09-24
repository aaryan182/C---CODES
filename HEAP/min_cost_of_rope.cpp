#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(long long arr[], long long n) {
        // Creating a min heap (priority queue)
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Insert all the rope lengths into the min heap
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }

        long long cost = 0;

        // Continue until there is only one rope left in the heap
        while (pq.size() > 1) {
            // Extract the two smallest rope lengths from the heap
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            // Calculate the sum of the two smallest rope lengths
            long long sum = a + b;

            // Add the sum to the cost
            cost += sum;

            // Push the sum back into the heap
            pq.push(sum);
        }

        return cost;
    }
};

int main() {
    Solution solution;

    // Example usage:
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);

    long long minCost = solution.minCost(arr, n);

    cout << "Minimum cost of connecting the ropes: " << minCost << endl;

    return 0;
}

// This code is a C++ implementation of a solution to a problem that involves finding the minimum cost of connecting ropes of different lengths. 

// The code starts by creating a min heap (priority queue) using the `priority_queue` container in C++. The priority queue is defined to store `long long` values in ascending order. 

// Next, the code inserts all the rope lengths into the min heap using a for loop. The `push` function is used to insert each rope length into the priority queue.

// After that, the code initializes a variable `cost` to 0. This variable will be used to keep track of the total cost of connecting the ropes.

// The code then enters a while loop that continues until there is only one rope left in the heap. The condition for the while loop is `pq.size() > 1`, which means that the loop will continue as long as there are more than one rope in the heap.

// Inside the while loop, the code extracts the two smallest rope lengths from the heap using the `top` function. The `top` function returns the smallest element in the heap without removing it. The two smallest rope lengths are stored in variables `a` and `b`.

// Next, the code calculates the sum of the two smallest rope lengths and stores it in a variable `sum`.

// The sum of the two smallest rope lengths is then added to the `cost` variable.

// Finally, the sum is pushed back into the heap using the `push` function.

// Once the while loop finishes, the code returns the final value of the `cost` variable, which represents the minimum cost of connecting all the ropes.