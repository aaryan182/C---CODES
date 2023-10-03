#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int src, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    visited[src] = true;
    
    for(int neighbour : adj[src]) {
        if(!visited[neighbour]) {
            if(isCyclicDFS(neighbour, src, visited, adj)) {
                return true;
            }
        } else if(neighbour != parent) {
            // If a visited neighbour is not the parent of the current node, a cycle exists
            return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(isCyclicDFS(i, -1, visited, adj)) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}
    };
    int n = 3;
    int m = 3;
    
    cout << "Cycle present: " << cycleDetection(edges, n, m) << endl;  // Output: Yes

    return 0;
}


// This code is used to detect cycles in an undirected graph. It uses a depth-first search (DFS) algorithm to traverse the graph and check for cycles.

// The `isCyclicDFS` function takes in the current node `src`, the parent node `parent`, a map `visited` to keep track of visited nodes, and an adjacency list `adj` to represent the graph.

// First, it marks the current node as visited by setting `visited[src]` to `true`.

// Then, it iterates over all the neighbors of the current node using a for-each loop. For each neighbor, it checks if it has not been visited yet (`!visited[neighbour]`). If it hasn't been visited, it recursively calls `isCyclicDFS` on that neighbor, passing in the current node as the parent. If the recursive call returns `true`, it means a cycle has been found, so the function returns `true`.

// If the neighbor has already been visited, it checks if it is not the parent of the current node (`neighbour != parent`). If it is not the parent, it means a cycle exists, so the function returns `true`.

// If none of the above conditions are met, the function continues to the next neighbor.

// If the function reaches the end of the loop without finding a cycle, it returns `false`.

// The `cycleDetection` function takes in a vector of edges, the number of nodes `n`, and the number of edges `m`.

// First, it initializes an empty adjacency list `adj` using an unordered map.

// Then, it iterates over the edges and adds them to the adjacency list. For each edge, it adds both nodes to each other's list of neighbors.

// Next, it initializes an empty map `visited` to keep track of visited nodes.

// Then, it iterates over all the nodes. For each node, if it has not been visited yet (`!visited[i]`), it calls `isCyclicDFS` on that node, passing in -1 as the parent (since it is the starting node). If `isCyclicDFS` returns `true`, it means a cycle has been found, so the function returns "Yes".

// If the function reaches the end of the loop without finding a cycle, it returns "No".