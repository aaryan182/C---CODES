// This code implements a function called `spiralOrder` that takes a 2D vector `A` as input and returns a 1D vector `result`. The `result` vector contains the elements of the input matrix `A` in spiral order.

// The code first checks if the input matrix `A` is empty. If it is empty, it returns an empty `result` vector.

// Next, it initializes variables `m` and `n` to store the number of rows and columns in the input matrix `A`, respectively.

// Then, it initializes variables `top`, `bottom`, `left`, and `right` to keep track of the boundaries of the current spiral. These variables are initially set to the outermost boundaries of the matrix.

// The code then enters a while loop that continues as long as the top boundary is less than or equal to the bottom boundary and the left boundary is less than or equal to the right boundary. This condition ensures that there are still elements to be traversed in the spiral.

// Inside the while loop, the code traverses the top row of the current spiral by using a for loop. It starts from the left boundary and goes up to the right boundary. It appends each element to the `result` vector.

// After traversing the top row, the `top` variable is incremented to move the top boundary down by one.

// Next, the code traverses the right column of the current spiral by using another for loop. It starts from the top boundary and goes down to the bottom boundary. It appends each element to the `result` vector.

// After traversing the right column, the `right` variable is decremented to move the right boundary to the left by one.

// The code then checks if the top boundary is still less than or equal to the bottom boundary. If it is, it means there are still rows to be traversed in the current spiral. In this case, it traverses the bottom row of the current spiral by using a for loop. It starts from the right boundary and goes to the left boundary. It appends each element to the `result` vector.

// After traversing the bottom row, the `bottom` variable is decremented to move the bottom boundary up by one.

// Next, the code checks if the left boundary is still less than or equal to the right boundary. If it is, it means there are still columns to be traversed in the current spiral. In this case, it traverses the left column of the current spiral by using a for loop. It starts from the bottom boundary and goes up to the top boundary. It appends each element to the `result` vector.

// After traversing the left column, the `left` variable is incremented to move the left boundary to the right by one.

// The while loop continues until all elements in the matrix have been traversed in spiral order.

// Finally, the code returns the `result` vector containing the elements of the input matrix `A` in spiral order.



vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
     vector<int> result;

    if (A.empty()) {
        return result;
    }

    int m = A.size();    // Number of rows
    int n = A[0].size(); // Number of columns

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse the top row
        for (int i = left; i <= right; ++i) {
            result.push_back(A[top][i]);
        }
        ++top;

        // Traverse the right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(A[i][right]);
        }
        --right;

        // Traverse the bottom row
        if (top <= bottom) {  // Check to avoid duplicate traversal
            for (int i = right; i >= left; --i) {
                result.push_back(A[bottom][i]);
            }
            --bottom;
        }

        // Traverse the left column
        if (left <= right) {  // Check to avoid duplicate traversal
            for (int i = bottom; i >= top; --i) {
                result.push_back(A[i][left]);
            }
            ++left;
        }
    }

    return result;

}
