// Question: Suppose a sorted array A is rotated at some pivot unknown to you beforehand.
// (i.e., 1 2 4 5 6 7 might become 4 5 6 7 1 2).
// Find the minimum element.
// The array will not contain duplicates.
// Note:- Use the circular rotated property of the array to solve the problem.

// Input 1:-
// A = [7, 2, 4, 5]
// Output 1:-
// 2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(const vector<int> &A)
    {
        int low = 0;
        int high = A.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (A[mid] > A[high])
            {
                // The pivot is to the right of mid, so minimum is in the right half
                low = mid + 1;
            }
            else
            {
                // The pivot is to the left of mid, so minimum is in the left half
                high = mid;
            }
        }
        return A[low];
    }
};

int main()
{
    Solution solution;

    vector<int> rotatedArray = {4, 5, 6, 7, 1, 2, 3};
    int minValue = solution.findMin(rotatedArray);

    cout << "Minimum element in the rotated array: " << minValue << endl;

    return 0;
}

// This code is written in C++ and it finds the minimum element in a rotated sorted array.

// First, the code includes the necessary header file `bits/stdc++.h` which includes all the standard C++ libraries.

// Then, a class `Solution` is defined. This class has a public member function `findMin` which takes a constant reference to a vector of integers `A` as input and returns an integer.

// Inside the `findMin` function, two variables `low` and `high` are initialized. `low` is set to 0 and `high` is set to the size of the input vector `A` minus 1.

// Then, a while loop is used to perform a binary search to find the minimum element. The loop continues as long as `low` is less than `high`.

// Inside the loop, a variable `mid` is calculated as the average of `low` and `high` using the formula `low + (high - low) / 2`. This is done to avoid integer overflow.

// Then, an if-else statement is used to check if the element at index `mid` is greater than the element at index `high`. If it is, it means that the pivot (the point where the array is rotated) is to the right of `mid`, so the minimum element must be in the right half of the array. In this case, `low` is updated to `mid + 1`.

// If the element at index `mid` is not greater than the element at index `high`, it means that the pivot is to the left of `mid`, so the minimum element must be in the left half of the array. In this case, `high` is updated to `mid`.

// Once the while loop ends, the minimum element is found and its value is returned by accessing the element at index `low` in the input vector `A`.

// In the `main` function, an instance of the `Solution` class is created.

// A vector `rotatedArray` is initialized with some values representing a rotated sorted array.

// The `findMin` function is called on the `rotatedArray` and the returned value is stored in the variable `minValue`.

// Finally, the minimum element is printed to the console using `cout`.