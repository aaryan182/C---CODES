// This code demonstrates the implementation of the insertion sort algorithm in C++. 

// The insertion sort algorithm works by dividing the input array into two parts: a sorted part and an unsorted part. Initially, the sorted part contains only the first element of the array, and the unsorted part contains the remaining elements. The algorithm then iterates through the unsorted part, selecting one element at a time and inserting it into its correct position in the sorted part.

// The `insertionSort` function takes an array `arr` and its size `n` as input. It starts by iterating through the array from the second element (`i = 1`) to the last element (`i < n`). For each element, it selects the element to be inserted (`key`) and initializes a variable `j` to track the index of the element being compared.

// The algorithm then enters a while loop that continues as long as `j` is greater than or equal to 0 and the element at index `j` is greater than `key`. Inside the while loop, it shifts the element at index `j` to the right by assigning `arr[j + 1]` the value of `arr[j]`. This process continues until the correct position for `key` is found.

// After the while loop, the algorithm places `key` at its correct position by assigning `arr[j + 1]` the value of `key`. This completes the insertion of the current element into the sorted part of the array.

// The `main` function demonstrates the usage of the `insertionSort` function. It initializes an array `arr` with some values and calculates the size of the array using the `sizeof` operator. It then prints the original array using a for loop and the `std::cout` object. 

// Next, it calls the `insertionSort` function to sort the array. 

// Finally, it prints the sorted array using another for loop and the `std::cout` object.




#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];   // Select the element to be inserted at the right position
        int j = i - 1;      // Initialize a variable to track the index of the element being compared

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift the element to the right
            j = j - 1;
        }
        
        arr[j + 1] = key;  // Place the key element at its correct position
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    insertionSort(arr, n);
    
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

