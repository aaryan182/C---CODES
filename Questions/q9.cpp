// Write a C++ program to find the maximum sum subarray within a given array of integers. (Hint: Kadane's algorithm)

#include <bits/stdc++.h>
using namespace std;

int findMaxSubarraySum(int arr[], int size)
{
    int maxSum = INT_MIN; // Initialize maxSum as the smallest possible value
    int currentSum = 0;

    for (int i = 0; i < size; ++i)
    {
        currentSum += arr[i]; // Add the current element to the running sum

        if (currentSum > maxSum)
        {
            maxSum = currentSum; // Update maxSum if currentSum is greater
        }

        if (currentSum < 0)
        {
            currentSum = 0; // Reset currentSum to 0 if it becomes negative
        }
    }

    return maxSum; // Return the maximum subarray sum
}

int main()
{
    int size;
    cout << "enter the size of the array " << endl;
    cin >> size;

    int arr[size];
    cout << "enter the elements of the array " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int maxSubarraySum = findMaxSubarraySum(arr, size);
    cout << "maximum subarray sum is : " << maxSubarraySum << endl;

    return 0;
}