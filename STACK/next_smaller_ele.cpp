#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next smaller elements: ";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

// Explanation:
// The nextSmallerElement function takes a vector arr and an integer n as input. It returns a vector ans containing the next smaller element for each element in arr.
// In the main function, we define an example input vector arr with values {4, 8, 5, 2, 25} and get its size n.
// We then call the nextSmallerElement function with arr and n as arguments, and store the result in the result vector.
// Next, we iterate over the result vector and print each element, which represents the next smaller element for the corresponding element in arr.
// In this example, the output will be: "Next smaller elements: 2 5 2 -1 -1".
// The next smaller element for 4 is 2.
// The next smaller element for 8 is 5.
// The next smaller element for 5 is 2.
// The next smaller element for 2 is -1 (no smaller element exists after it).
// The next smaller element for 25 is -1 (no smaller element exists after it).
// The code uses a stack to keep track of the next smaller elements. It starts by pushing -1 onto the stack as a sentinel value. Then, it iterates over the input vector arr in reverse order. For each element, it compares it with the top of the stack. If the top of the stack is greater than or equal to the current element, it pops elements from the stack until the top of the stack is smaller than the current element or the stack becomes empty. Finally, it assigns the top of the stack (which represents the next smaller element) to the corresponding position in the ans vector and pushes the current element onto the stack.

