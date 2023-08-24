// Q)Given an one-dimensional unsorted array A containing N integers.
// You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.
// Return 1 if any such pair exists else return 0.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    sort(A.begin(), A.end());

    int left = 0;
    int right = 1;

    while (right < A.size() && left < A.size())
    {
        if (left != right && A[right] - A[left] == B)
        {
            return 1;
        }
        else if (A[right] - A[left] < B)
        {
            right++;
        }
        else
        {
            left++;
        }
    }
    return 0;
}

int main()
{
    vector<int> A = {2, 3, 5, 8, 10};
    int B = 2;

    int result = solve(A, B);
    if (result == 1)
    {
        cout << "A pair with difference " << B << " exists" << endl;
    }
    else
    {
        cout << "No pair with difference " << B << " found" << endl;
    }
    return 0;
}

// This code is a function called `solve` that takes in a vector of integers `A` and an integer `B` as parameters. The function returns an integer.
// The first line of the code sorts the vector `A` in ascending order using the `sort` function from the C++ standard library.
// The next two lines initialize two variables `left` and `right` to 0 and 1 respectively.
// The code then enters a while loop that continues as long as both `right` and `left` are within the bounds of the vector `A`.
// Inside the while loop, there is an if-else statement that checks two conditions. 
// The first condition `left != right && A[right] - A[left] == B` checks if the difference between the elements at indices `right` and `left` in the sorted vector `A` is equal to `B`. If this condition is true, the function returns 1.
// If the first condition is not true, the code checks the second condition `A[right] - A[left] < B`. This condition checks if the difference between the elements at indices `right` and `left` in the sorted vector `A` is less than `B`. If this condition is true, the variable `right` is incremented by 1.
// If both conditions are false, the variable `left` is incremented by 1.
// The while loop continues until either `right` or `left` reaches the end of the vector `A`.
// If the while loop completes without finding a pair of elements with a difference of `B`, the function returns 0.