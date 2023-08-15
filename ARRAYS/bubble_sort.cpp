// This code demonstrates the implementation of the Bubble Sort algorithm in C++. 

// Bubble Sort is a simple comparison-based sorting algorithm. It works by repeatedly swapping adjacent elements if they are in the wrong order. The algorithm continues to iterate through the array until no more swaps are needed, indicating that the array is sorted.

// The `bubbleSort` function takes a reference to a vector of integers as input. It first initializes a variable `n` with the size of the input array. It also declares a boolean variable `swapped` to track if any swaps were made in an iteration.

// The outer loop iterates `n-1` times, where `n` is the size of the array. This is because after each iteration, the largest element in the unsorted part of the array "bubbles" up to its correct position at the end. Therefore, the last `i` elements are already in place and do not need to be checked.

// Inside the outer loop, the `swapped` flag is set to `false` at the beginning of each iteration. This flag is used to determine if any swaps were made in the inner loop. If no swaps were made, it means that the array is already sorted and the algorithm can terminate early.

// The inner loop iterates from the first element to the `n-i-1` element. This is because after each iteration of the inner loop, the largest element in the unsorted part of the array is moved to its correct position at the end. Therefore, there is no need to check the last `i` elements in subsequent iterations.

// Inside the inner loop, the algorithm compares each element with its adjacent element. If the current element is greater than the next element, they are swapped using the `std::swap` function from the `<algorithm>` library. The `swapped` flag is set to `true` to indicate that a swap occurred.

// After the inner loop completes, the algorithm checks the `swapped` flag. If it is still `false`, it means that no swaps were made in the inner loop and the array is already sorted. In this case, the algorithm breaks out of the outer loop and terminates early.

// In the `main` function, a vector `arr` is initialized with a set of integers. The original array is then printed using a `for` loop and the `std::cout` object. The `bubbleSort` function is called to sort the array. Finally, the sorted array is printed using another `for` loop and the `std::cout` object.

// The output of the program will display the original array followed by the sorted array.

#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;  // Flag to track if any swaps were made in an iteration

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Last i elements are already in place, so no need to check them
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;  // Set the flag to true since a swap occurred
            }
        }

        // If no two elements were swapped by inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
