#include <bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited,
                   unordered_map<int, bool> &dfsVisited,
                   unordered_map<int, list<int>> &adj) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected) return true;
        } else if (dfsVisited[neighbour]) {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if (cycleFound) return true;
        }
    }
    return false;
}

int main() {
    int n = 3;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 1}};

    if (detectCycleInDirectedGraph(n, edges)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle in the graph." << endl;
    }

    return 0;
}


// This code is used to detect cycles in a directed graph. It uses a depth-first search (DFS) algorithm to traverse the graph and check for cycles.

// The `checkCycleDFS` function takes four parameters: `node`, `visited`, `dfsVisited`, and `adj`. 
// - `node` represents the current node being visited.
// - `visited` is an unordered map that keeps track of whether a node has been visited or not.
// - `dfsVisited` is an unordered map that keeps track of whether a node has been visited during the current DFS traversal or not.
// - `adj` is an unordered map that represents the adjacency list of the graph, where each node is mapped to a list of its neighboring nodes.

// The function starts by marking the current node as visited and dfsVisited. Then, it iterates over each neighbor of the current node. If a neighbor has not been visited, the function recursively calls itself with the neighbor as the new current node. This is done to explore all possible paths in the graph.

// If a neighbor has been visited during the current DFS traversal (i.e., it is present in dfsVisited), it means that a cycle has been detected. In this case, the function returns true to indicate that a cycle has been found.

// After visiting all neighbors of the current node, the function marks the current node as not visited in dfsVisited and returns false to indicate that no cycle has been found.

// The `detectCycleInDirectedGraph` function takes two parameters: `n` and `edges`.
// - `n` represents the number of nodes in the graph.
// - `edges` is a vector of pairs representing the edges of the graph.

// The function first creates an empty adjacency list `adj` and populates it using the `edges` vector. Each pair in the `edges` vector represents an edge from the first element to the second element.

// Then, it creates two empty unordered maps `visited` and `dfsVisited` to keep track of visited nodes and nodes visited during the current DFS traversal, respectively.

// Next, the function iterates over all nodes from 1 to `n` and checks if each node has been visited. If a node has not been visited, it calls the `checkCycleDFS` function with the node as the current node. If a cycle is found during the DFS traversal, the function returns true to indicate that a cycle has been detected.

// If no cycle is found after visiting all nodes, the function returns false to indicate that no cycle has been detected in the directed graph.