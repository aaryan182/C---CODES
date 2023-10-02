#include <bits/stdc++.h>
using namespace std;

void findPaths(vector<vector<int>>& maze, int x, int y, int n, string path, vector<string>& result) {
    // Base case: if the rat reaches the destination
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    // Mark the cell as visited
    maze[x][y] = 0;
    
    // Check boundaries and cell value before moving right
    if (y + 1 < n && maze[x][y + 1] == 1) {
        findPaths(maze, x, y + 1, n, path + "R", result);
    }

    // Check boundaries and cell value before moving down
    if (x + 1 < n && maze[x + 1][y] == 1) {
        findPaths(maze, x + 1, y, n, path + "D", result);
    }

    // Check boundaries and cell value before moving up
    if (x - 1 >= 0 && maze[x - 1][y] == 1) {
        findPaths(maze, x - 1, y, n, path + "U", result);
    }

    // Check boundaries and cell value before moving left
    if (y - 1 >= 0 && maze[x][y - 1] == 1) {
        findPaths(maze, x, y - 1, n, path + "L", result);
    }

    // Unmark the cell before backtracking
    maze[x][y] = 1;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> result;
    string path = "";
    if(arr[0][0] == 1) // Ensure starting point is accessible
        findPaths(arr, 0, 0, n, path, result);
    return result;
}



int main() {
    int n = 3;
    vector<vector<int>> maze = {{1, 0, 1},
                                {1, 1, 1},
                                {0, 1, 1}};
    vector<string> paths = searchMaze(maze, n);
    
    if(paths.empty()) {
        cout << "No path exists!" << endl;
    } else {
        // Output all possible paths
        for (const auto& path : paths) {
            cout << path << endl;
        }
    }
    
    return 0;
}


// This code is a program that finds all possible paths in a maze from the top-left corner to the bottom-right corner. The maze is represented as a 2D vector of integers, where 1 represents a valid path and 0 represents a blocked path.

// The program uses a recursive function called `findPaths` to explore all possible paths. The function takes the maze, the current position (x, y), the size of the maze (n), the current path, and a vector to store the result.

// The base case of the recursion is when the rat reaches the destination (x == n - 1 and y == n - 1). In this case, the current path is added to the result vector and the function returns.

// Before exploring a cell, the program marks it as visited by setting its value to 0.

// The program then checks the boundaries and the value of the cell before moving in each direction (right, down, up, left). If the cell is within the boundaries and its value is 1 (a valid path), the `findPaths` function is called recursively with the updated position and path.

// After exploring all possible paths from a cell, the program unmarks the cell by setting its value back to 1 before backtracking.

// The `searchMaze` function is the entry point of the program. It initializes an empty result vector and an empty path string. If the starting point of the maze (arr[0][0]) is accessible (value is 1), the `findPaths` function is called with the starting position and path.

// Finally, in the `main` function, the program creates a maze and calls the `searchMaze` function to find all possible paths. If no path exists, it prints "No path exists!". Otherwise, it prints all the paths found.