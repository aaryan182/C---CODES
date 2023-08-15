// This code implements the Quick Sort algorithm to sort an array of integers in ascending order. 

// The Quick Sort algorithm works by selecting a pivot element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted. 

// The `partition` function is used to rearrange the elements in the array. It takes in the array, the low index, and the high index as parameters. It chooses the last element as the pivot and initializes the index of the smaller element to `low - 1`. 

// The function then iterates through the array from `low` to `high - 1`. If the current element is smaller than or equal to the pivot, it increments the index of the smaller element and swaps the current element with the element at the smaller index. This ensures that all elements smaller than the pivot are moved to the left of the pivot. 

// After the loop, the pivot element is placed in its correct position by swapping it with the element at the index `i + 1`. The function then returns the index of the pivot element. 

// The `quickSort` function is the main function that implements the Quick Sort algorithm. It takes in the array, the low index, and the high index as parameters. 

// In the function, if the low index is less than the high index, the array is partitioned into two sub-arrays using the `partition` function. The pivot index is obtained and the `quickSort` function is recursively called on the sub-arrays to sort them. 

// In the `main` function, an array of integers is initialized and its size is stored in the variable `n`. The original array is printed using a for-each loop. 

// The `quickSort` function is then called on the array to sort it. 

// Finally, the sorted array is printed using a for-each loop.

#include <iostream>
#include <vector>

// Partition function to rearrange elements in the array
int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++; // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array into two sub-arrays and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original Array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
