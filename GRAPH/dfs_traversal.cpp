#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;
    
    for(auto &i : adj[node]) {
        if(!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    for(const auto &edge: edges) {
        int u = edge[0];
        int v = edge[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line for directed graph
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {3,4}};
    auto ans = depthFirstSearch(5, edges);
    
    for(const auto &component: ans) {
        for(const int &node: component) {
            cout << node << " ";
        }
        cout << "\n";
    }
    
    return 0;
}


// This code is an implementation of the Depth First Search (DFS) algorithm to find connected components in an undirected graph.

// The `dfs` function is a recursive function that takes in a starting node, a map of visited nodes, an adjacency list, and a vector to store the connected component. 

//  It adds the current node to the component vector and marks it as visited in the visited map.
//  It then iterates over the adjacent nodes of the current node.
//  If an adjacent node has not been visited, it recursively calls the `dfs` function on that node.
//  This process continues until all connected nodes have been visited and added to the component vector.

// The `depthFirstSearch` function takes in the number of vertices `V` and a vector of edges. 

//  It initializes an empty adjacency list `adj` using an unordered map.
//  It then iterates over each edge in the edges vector.
//  For each edge, it adds the second vertex to the adjacency list of the first vertex and vice versa (for an undirected graph).
//  It then initializes an empty vector `ans` to store the connected components.
//  It also initializes an empty visited map.
//  It then iterates over each vertex from 0 to `V-1`.
//  If a vertex has not been visited, it creates an empty vector `component` and calls the `dfs` function on that vertex.
//  The `dfs` function adds all connected nodes to the `component` vector.
//  Finally, it adds the `component` vector to the `ans` vector.
//  After iterating over all vertices, it returns the `ans` vector containing all the connected components of the graph.