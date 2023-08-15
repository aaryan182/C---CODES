// This code is a function that takes in a vector of integers `A` and an integer `B` as input. It is trying to find the count of occurrences of `B` in the vector `A`.

// The function first uses the `lower_bound` function to find the first occurrence of `B` in the vector `A`. The `lower_bound` function returns an iterator pointing to the first element that is not less than `B`. If `B` is not found in the vector, the `lower_bound` function will return an iterator pointing to the end of the vector.

// Next, the function uses the `upper_bound` function to find the first element that is greater than `B` in the vector `A`. The `upper_bound` function returns an iterator pointing to the first element that is greater than `B`. If `B` is not found in the vector, the `upper_bound` function will return an iterator pointing to the end of the vector.

// The function then checks if the `lower` iterator is pointing to the end of the vector or if the value at the `lower` iterator is not equal to `B`. If either of these conditions is true, it means that `B` was not found in the vector, so the function returns 0.

// If `B` is found in the vector, the function returns the difference between the `upper` iterator and the `lower` iterator. This difference represents the count of occurrences of `B` in the vector `A`.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCount(const vector<int> &A, int B)
    {
        auto lower = lower_bound(A.begin(), A.end(), B);
        auto upper = upper_bound(A.begin(), A.end(), B);

        if (lower == A.end() || *lower != B)
        {
            return 0; // Target not found
        }

        return upper - lower;
    }
};

int main()
{
    Solution solution;

    vector<int> arr = {1, 2, 2, 2, 3, 4, 4, 4, 4, 5};
    int target = 4;

    int count = solution.findCount(arr, target);

    cout << "Count of occurrences of " << target << " is: " << count << endl;

    return 0;
}
