// This code demonstrates the implementation of the Selection Sort algorithm in C++. 

// The `selectionSort` function takes a reference to a vector of integers as input. It first determines the size of the vector using the `size` function. 

// The outer loop iterates from the first element to the second-to-last element of the vector. It keeps track of the index with the minimum value in the unsorted part of the array using the `minIndex` variable. Initially, it assumes that the current index (`i`) has the minimum value.

// The inner loop starts from the next index (`i + 1`) and iterates until the last element of the vector. It compares each element with the element at the `minIndex` and updates `minIndex` if a smaller element is found.

// After finding the index of the minimum element in the unsorted part of the array, the `swap` function is used to swap the minimum element with the first element of the unsorted part. This effectively moves the minimum element to its correct position in the sorted part of the array.

// The `main` function initializes a vector `arr` with some integer values. It then prints the original array using a `for` loop and the `cout` object. 

// Next, it calls the `selectionSort` function to sort the array. 

// Finally, it prints the sorted array using another `for` loop and the `cout` object.

#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume the current index has the minimum value

        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted part
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSort(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
