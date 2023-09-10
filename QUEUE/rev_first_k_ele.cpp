#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    // Step 1: Pop the first k elements from q and put them into a stack
    stack<int> s;
    for (int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Step 2: Fetch elements from the stack and push them back into q
    while (!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // Step 3: Fetch the remaining n-k elements from q and push them back into the stack
    int n = q.size(); // Get the current size of q
    int t = n - k;    // Number of elements to be pushed into the stack
    while (t--) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Step 4: Fetch elements from the stack and push them back into q
    while (!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    return q;
}

int main() {
    // Example usage
    queue<int> q;
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }
    
    int k = 3; // Number of elements to be moved to the end

    queue<int> modifiedQ = modifyQueue(q, k);

    cout << "Modified Queue: ";
    while (!modifiedQ.empty()) {
        cout << modifiedQ.front() << " ";
        modifiedQ.pop();
    }

    return 0;
}


// This code takes a queue of integers `q` and an integer `k` as input and modifies the queue according to the following steps:

// Step 1: Pop the first `k` elements from `q` and put them into a stack `s`.
// - This is done using a for loop that iterates `k` times.
// - In each iteration, the front element of `q` is removed using the `pop()` function and stored in a variable `val`.
// - The value of `val` is then pushed onto the stack `s` using the `push()` function.

// Step 2: Fetch elements from the stack `s` and push them back into `q`.
// - This is done using a while loop that continues until the stack `s` is empty.
// - In each iteration, the top element of `s` is removed using the `pop()` function and stored in a variable `val`.
// - The value of `val` is then pushed back onto `q` using the `push()` function.

// Step 3: Fetch the remaining `n-k` elements from `q` and push them back into the stack `s`.
// - The current size of `q` is stored in a variable `n` using the `size()` function.
// - The number of elements to be pushed into the stack is calculated as `t = n - k`.
// - This is done using a while loop that continues until `t` becomes 0.
// - In each iteration, the front element of `q` is removed using the `pop()` function and stored in a variable `val`.
// - The value of `val` is then pushed onto the stack `s` using the `push()` function.

// Step 4: Fetch elements from the stack `s` and push them back into `q`.
// - This is done using a while loop that continues until the stack `s` is empty.
// - In each iteration, the top element of `s` is removed using the `pop()` function and stored in a variable `val`.
// - The value of `val` is then pushed back onto `q` using the `push()` function.

// Finally, the modified queue `q` is returned as the output of the function.