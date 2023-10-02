#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n); 
    
    for(int i = 0; i < m; i++){ 
        int u = edges[i][0];
        int v = edges[i][1];
        
        if(u < n && v < n) { 
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        adj[i].push_back(i);
        for(const int& neighbor: ans[i]){
            adj[i].push_back(neighbor);
        }
    }
    return adj;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    vector<vector<int>> adjacencyList = printAdjacency(4, 3, edges);
    
    for(const auto& list: adjacencyList) {
        for(int node: list) {
            cout << node << ' ';
        }
        cout << '\n';
    }
    return 0;
}


// This code is a C++ program that creates an adjacency list representation of a graph. 

// The `printAdjacency` function takes three parameters: `n` (the number of nodes in the graph), `m` (the number of edges in the graph), and `edges` (a vector of vectors representing the edges of the graph). 

// Inside the function, an empty 2D vector called `ans` is created with `n` rows. This vector will store the adjacency list representation of the graph. 

// Then, a loop is started to iterate over each edge in the `edges` vector. For each edge, the source node `u` and the destination node `v` are extracted. 

// Next, a check is performed to ensure that both `u` and `v` are less than `n`. This check is necessary to avoid accessing out-of-bounds indices in the `ans` vector. 

// If the check passes, the destination node `v` is added to the adjacency list of the source node `u`, and vice versa. This is done by using the `push_back` function to add `v` to the `ans[u]` vector and `u` to the `ans[v]` vector. 

// After the loop finishes, another 2D vector called `adj` is created with `n` rows. This vector will store the final adjacency list representation of the graph. 

// Then, a loop is started to iterate over each node in the graph. For each node, the node itself is added to its own adjacency list by using the `push_back` function. 

// Next, a nested loop is started to iterate over each neighbor of the current node. The neighbors are obtained from the `ans` vector using a range-based for loop. For each neighbor, it is added to the adjacency list of the current node using the `push_back` function. 

// Finally, the `adj` vector is returned as the result of the `printAdjacency` function. 

// In the `main` function, a vector called `edges` is created to represent the edges of the graph. 

// Then, the `printAdjacency` function is called with the parameters `4` (the number of nodes), `3` (the number of edges), and `edges`. The result is stored in a vector called `adjacencyList`. 

// Next, a nested loop is started to iterate over each list in the `adjacencyList` vector. For each list, a loop is started to iterate over each node in the list. The nodes are printed to the console separated by a space. 

// After printing all the nodes in a list, a newline character is printed to move to the next line. 

// Finally, the `main` function returns `0` to indicate successful execution of the program.