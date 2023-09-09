#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};

int main()
{
    Solution solution;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int largestArea = solution.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << largestArea << endl;

    return 0;
}


// This code is a solution to find the largest rectangle area in a histogram. 

// The `Solution` class has two private helper functions: `nextSmallerElement` and `prevSmallerElement`. These functions are used to find the indices of the next smaller and previous smaller elements for each element in the input array.

// The `nextSmallerElement` function takes an array `arr` and its size `n` as input. It initializes an empty stack `s` and pushes -1 onto the stack. It also initializes an empty vector `ans` of size `n`. 

// The function then iterates over the elements of the array in reverse order, starting from the last element. For each element `curr`, it checks if the top element of the stack is not -1 and if the element at that index in the array is greater than or equal to `curr`. If this condition is true, it pops elements from the stack until the condition is no longer true. 

// After the while loop, the top element of the stack is assigned to `ans[i]` and the index `i` is pushed onto the stack. 

// Finally, the function returns the `ans` vector.

// The `prevSmallerElement` function is similar to `nextSmallerElement`, but it iterates over the elements of the array in forward order.

// The `largestRectangleArea` function takes a reference to a vector `heights` as input. It first calculates the size of the vector `n`.

// Then, it creates two vectors `next` and `prev` and assigns the results of calling the `nextSmallerElement` and `prevSmallerElement` functions with `heights` and `n` as arguments.

// Next, it initializes a variable `area` with a value of INT_MIN.

// The function then iterates over the elements of the `heights` vector. For each element `l`, it checks if the value at the corresponding index in the `next` vector is -1. If it is, it assigns the value of `n` to `next[i]`.

// It then calculates the width `b` of the rectangle by subtracting the value at the corresponding index in the `prev` vector from the value at the corresponding index in the `next` vector, and subtracting 1.

// It calculates the area of the rectangle by multiplying `l` and `b`, and assigns it to the variable `newArea`.

// Finally, it updates the value of `area` to be the maximum of `area` and `newArea`.

// The function returns the value of `area`, which represents the largest rectangle area in the histogram.