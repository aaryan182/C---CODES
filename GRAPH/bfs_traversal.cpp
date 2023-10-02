#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges) {
    for(const auto &edge: edges) {
        int u = edge.first;
        int v = edge.second;
        
        adjList[u].insert(v); // for directed graph remove this line
        adjList[v].insert(u); 
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode); // store frontNode into ans
        
        for(const auto &neighbour: adjList[frontNode]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    prepareAdjList(adjList, edges);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    
    return ans;
}

int main() {
    vector<pair<int, int>> edges = {{0,1}, {1,2}, {2,3}, {3,4}};
    vector<int> ans = bfsTraversal(5, edges);
    
    for(const int &node: ans) {
        cout << node << " ";
    }
    cout << "\n";
    
    return 0;
}


// This code is implementing a breadth-first search (BFS) traversal algorithm on a graph represented as an adjacency list.

// The `prepareAdjList` function takes in an empty adjacency list `adjList` and a vector of edges `edges`. It iterates through each edge in `edges` and adds the corresponding vertices to the adjacency list. For each edge, it inserts the second vertex into the set of neighbors for the first vertex, and vice versa. This step is necessary to represent an undirected graph. If the graph is directed, the line `adjList[u].insert(v);` should be removed.

// The `bfs` function takes in the adjacency list `adjList`, a map of visited nodes `visited`, a vector `ans` to store the traversal order, and a starting node `node`. It initializes a queue `q` and pushes the starting node into it. It also marks the starting node as visited in the `visited` map.

// The function then enters a while loop that continues until the queue is empty. In each iteration, it retrieves the front node from the queue using `q.front()` and removes it from the queue using `q.pop()`. It appends the front node to the `ans` vector to store the traversal order.

// Next, it iterates through each neighbor of the front node using a range-based for loop. If a neighbor has not been visited yet (as determined by the `visited` map), it pushes the neighbor into the queue and marks it as visited in the `visited` map.

// The `bfsTraversal` function takes in the number of nodes `n` and the vector of edges `edges`. It initializes an empty adjacency list `adjList`, an empty vector `ans` to store the traversal order, and an empty map `visited` to keep track of visited nodes.

// It then calls the `prepareAdjList` function to populate the adjacency list based on the given edges.

// Next, it iterates through each node from 0 to `n-1`. If a node has not been visited yet (as determined by the `visited` map), it calls the `bfs` function to perform a BFS traversal starting from that node.

// Finally, it returns the `ans` vector containing the BFS traversal order.