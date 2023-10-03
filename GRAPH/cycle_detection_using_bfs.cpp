#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    unordered_map<int, int> parent;
    
    parent[src] = -1;
    visited[src] = true;
    
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(int neighbour : adj[front]) {
            if(visited[neighbour] && neighbour != parent[front]) {
                return true;
            } else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
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
            if(isCyclicBFS(i, visited, adj)) {
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


// This code is used to detect cycles in an undirected graph using the Breadth-First Search (BFS) algorithm.

// The `isCyclicBFS` function takes three parameters: `src` (the source node), `visited` (an unordered map to keep track of visited nodes), and `adj` (an unordered map to represent the adjacency list of the graph). 

// Inside the function, a `parent` unordered map is created to keep track of the parent of each node. The `src` node is set as the parent of itself and marked as visited. 

// A queue `q` is created and the `src` node is pushed into it. 

// The while loop runs until the queue is empty. In each iteration, the front element of the queue is removed and stored in the `front` variable. 

// Then, for each neighbor of the `front` node, the following checks are performed:
// - If the neighbor is already visited and it is not the parent of the `front` node, then a cycle is detected and the function returns `true`.
// - If the neighbor is not visited, it is pushed into the queue, marked as visited, and its parent is set as the `front` node.

// If no cycle is detected after traversing all the nodes, the function returns `false`.

// The `cycleDetection` function takes three parameters: `edges` (a vector of vectors representing the edges of the graph), `n` (the number of nodes), and `m` (the number of edges).

// Inside the function, an unordered map `adj` is created to represent the adjacency list of the graph. The edges are added to the adjacency list by iterating over the `edges` vector.

// Another unordered map `visited` is created to keep track of visited nodes.

// Then, for each node in the graph, if it is not visited, the `isCyclicBFS` function is called with the current node, `visited`, and `adj` as arguments. If a cycle is detected, the function returns "Yes".

// If no cycle is detected after traversing all the nodes, the function returns "No".