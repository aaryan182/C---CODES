// Write a recursive function to perform a binary search on a sorted array to find a given target element.

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int target, int left, int right)
{
    if (left > right)
    {
        // Base case: Element not found
        return -1;
    }

    // Calculate the middle index
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        // Base case: Element found at the middle index
        return mid;
    }
    else if (arr[mid] > target)
    {
        // If the middle element is greater than the target,
        // search in the left half of the array (excluding middle)
        return binarySearch(arr, target, left, mid - 1);
    }
    else
    {
        // If the middle element is less than the target,
        // search in the right half of the array (excluding middle)
        return binarySearch(arr, target, mid + 1, right);
    }
}

int main()
{
    int sortedArray[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int numElements = sizeof(sortedArray) / sizeof(sortedArray[0]); // Calculate the size of the array
    int target;

    cout << "Enter the target element: ";
    cin >> target;

    int result = binarySearch(sortedArray, target, 0, numElements - 1); // Pass the size as numElements

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}
