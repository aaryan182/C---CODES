#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
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

    vector<int> result = prevSmallerElement(arr, n);

    cout << "Previous smaller elements: ";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

// This code is a function that takes in a vector of integers arr and an integer n as input. It returns a vector ans which contains the previous smaller element for each element in the input vector.

// The function uses a stack data structure to keep track of the previous smaller elements. It initializes the stack with a single element -1. This is done to handle the case when there is no previous smaller element for the first element in the input vector.

// The function then iterates over each element in the input vector using a for loop. For each element, it checks if the top element of the stack is greater than or equal to the current element. If it is, it pops elements from the stack until the top element is smaller than the current element.

// After the while loop, the function assigns the top element of the stack to the corresponding index in the ans vector. This represents the previous smaller element for the current element.

// Finally, the function pushes the current element onto the stack and continues to the next iteration of the for loop.

// Once all elements in the input vector have been processed, the function returns the ans vector which contains the previous smaller element for each element in the input vector.