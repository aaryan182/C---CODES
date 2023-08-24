// Q) Given a sorted array A consisting of duplicate elements.
// Your task is to remove all the duplicates and return the length of the sorted array of distinct elements consisting of all distinct elements present in A.
// Note: You need to update the elements of array A by removing all the duplicates

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A)
{
    if (A.empty())
    {
        return 0; // If the array is empty, no duplicates to remove
    }

    int uniqueIndex = 0; // Index to store the unique elements

    for (int i = 1; i < A.size(); ++i)
    {
        if (A[i] != A[uniqueIndex])
        {
            uniqueIndex++;
            A[uniqueIndex] = A[i]; // Update the unique elements
        }
    }

    return uniqueIndex + 1; // Return the length of the array with distinct elements
}

int main()
{
    vector<int> A = {1, 1, 2, 2, 2, 3, 4, 5, 5, 5};

    int newLength = removeDuplicates(A);

    cout << "Length of array with distinct elements: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

// This code is a function that removes duplicates from a vector of integers. 
// First, it checks if the vector is empty. If it is, there are no duplicates to remove, so it returns 0.
// Next, it initializes a variable called `uniqueIndex` to 0. This variable will be used to keep track of the index where the unique elements should be stored.
// Then, it starts a loop that iterates over the vector starting from the second element (index 1). 
// Inside the loop, it compares the current element (`A[i]`) with the element at the `uniqueIndex` position (`A[uniqueIndex]`). If they are different, it means that the current element is a new unique element. In this case, it increments `uniqueIndex` by 1 and updates the element at the new `uniqueIndex` position with the current element. This effectively moves the unique element to the correct position in the vector.
// After the loop finishes, it returns `uniqueIndex + 1`. This value represents the length of the vector with distinct elements, as `uniqueIndex` is the index of the last unique element. Adding 1 accounts for the fact that indices start from 0.