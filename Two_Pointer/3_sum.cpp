// Q)Given an array A of N integers, find three integers in A such that the sum is closest to a given number B. Return the sum of those three integers.
// Assume that there will only be one solution.

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());

    int closestSum = INT_MAX;
    int minDiff = INT_MAX;

    for (int i = 0; i < A.size() - 2; ++i)
    {
        int left = i + 1;
        int right = A.size() - 1;

        while (left < right)
        {
            int sum = A[i] + A[left] + A[right];
            int diff = sum - B;

            if (diff == 0)
            {
                return sum;
            }

            if (abs(diff) < abs(minDiff))
            {
                minDiff = diff;
                closestSum = sum;
            }

            if (diff < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return closestSum;
}

int main()
{
    vector<int> A = {-1, 2, 1, -4};
    int B = 1;

    int result = threeSumClosest(A, B);
    cout << "closest sum to " << B << " is : " << result << endl;
    return 0;
}


// This code is a function that takes in a vector of integers `A` and an integer `B`. It finds the sum of three integers in the vector that is closest to the target integer `B` and returns that sum.
// The code first sorts the vector `A` in ascending order using the `sort` function from the C++ standard library.
// Then, it initializes two variables `closestSum` and `minDiff` to store the closest sum found so far and the minimum difference between the sum and the target.
// The code then enters a loop that iterates over the vector `A` from the first element to the second-to-last element. This is because we need at least three elements to form a sum.
// Inside the loop, two pointers `left` and `right` are initialized. The `left` pointer starts from the element next to the current element `i`, and the `right` pointer starts from the last element of the vector.
// The code then enters a while loop that continues as long as the `left` pointer is less than the `right` pointer. This loop is used to find the closest sum by adjusting the pointers.
// Inside the while loop, the code calculates the sum of the current three elements `A[i]`, `A[left]`, and `A[right]` and stores it in the variable `sum`. It also calculates the difference between the sum and the target `B` and stores it in the variable `diff`.
// If the difference is equal to 0, it means that the sum is equal to the target, so the code returns the sum.
// If the absolute value of the difference is less than the absolute value of the minimum difference found so far, the code updates the minimum difference and the closest sum.
// Finally, if the difference is less than 0, it means that the sum is smaller than the target, so the `left` pointer is incremented. Otherwise, the `right` pointer is decremented.
// After the while loop ends, the code moves to the next iteration of the outer loop and repeats the process with the next element as the starting point for the `left` pointer.
// Once the outer loop finishes iterating over all elements, the code returns the closest sum found.