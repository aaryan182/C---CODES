int Solution::solve(int A, int B) {
    // Count squares on four diagonals
    int upperLeft = min(A - 1, B - 1);
    int upperRight = min(A - 1, 8 - B);
    int lowerLeft = min(8 - A, B - 1);
    int lowerRight = min(8 - A, 8 - B);
    
    // Total number of squares that can be visited by the Bishop in one move
    int totalSquares = upperLeft + upperRight + lowerLeft + lowerRight;
    
    return totalSquares;
}

// This code is a function that calculates the number of squares that can be visited by a Bishop on a chessboard in one move. The function takes two parameters, A and B, which represent the coordinates of the Bishop on the chessboard.

// The first step in the function is to count the number of squares on the four diagonals that the Bishop can move to. This is done by calculating the minimum of the distance between the Bishop's position and the edges of the chessboard in each direction.

// - `upperLeft` represents the number of squares on the diagonal going from the Bishop's position towards the upper left corner of the chessboard. It is calculated by taking the minimum of `A - 1` and `B - 1`, which ensures that the Bishop does not move off the chessboard in this direction.

// - `upperRight` represents the number of squares on the diagonal going from the Bishop's position towards the upper right corner of the chessboard. It is calculated by taking the minimum of `A - 1` and `8 - B`, which ensures that the Bishop does not move off the chessboard in this direction.

// - `lowerLeft` represents the number of squares on the diagonal going from the Bishop's position towards the lower left corner of the chessboard. It is calculated by taking the minimum of `8 - A` and `B - 1`, which ensures that the Bishop does not move off the chessboard in this direction.

// - `lowerRight` represents the number of squares on the diagonal going from the Bishop's position towards the lower right corner of the chessboard. It is calculated by taking the minimum of `8 - A` and `8 - B`, which ensures that the Bishop does not move off the chessboard in this direction.

// After counting the squares on the four diagonals, the total number of squares that can be visited by the Bishop in one move is calculated by summing up the values of `upperLeft`, `upperRight`, `lowerLeft`, and `lowerRight`.

// Finally, the function returns the total number of squares.Ω