#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list 
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // find all degrees
    vector<int> indegree(v, 0);
    for(auto i: adj) {
        for(auto j: i.second) {
            indegree[j]++;
        }
    }

    // push nodes with 0 indegree into the queue 
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // perform bfs 
    vector<int> ans;
    while(!q.empty()) {
        int front = q.front(); 
        q.pop();

        // store the result
        ans.push_back(front);

        // update the indegree of each neighbor
        for(auto neighbour: adj[front]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}

int main() {
    // Example usage:
    vector<vector<int>> edges = {
        {0, 1}, 
        {1, 2},
        {2, 3},
        {2, 4}
    };
    vector<int> result = topologicalSort(edges, 5, 4);
    for(int i : result) {
        cout << i << " ";
    }
    return 0;
}


// This code is an implementation of the topological sort algorithm using a modified version of breadth-first search (BFS).

// The topological sort algorithm is used to find a linear ordering of the vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. In other words, it arranges the vertices in a way that respects the dependencies between them.

// Let's go through the code step by step:

// 1. The function `topologicalSort` takes three parameters: `edges`, `v`, and `e`. 
//    - `edges` is a 2D vector representing the edges of the graph. Each element in the vector is a pair of vertices (u, v) indicating a directed edge from vertex u to vertex v.
//    - `v` is the number of vertices in the graph.
//    - `e` is the number of edges in the graph.

// 2. The code starts by creating an adjacency list `adj` using an unordered map. The adjacency list represents the graph as a collection of lists, where each list contains the vertices that are adjacent to a particular vertex. This step is done by iterating over the `edges` vector and adding the vertices to the corresponding adjacency list.

// 3. Next, the code calculates the indegree of each vertex. The indegree of a vertex is the number of incoming edges to that vertex. This is done by iterating over the adjacency list and incrementing the indegree of each neighbor for every vertex.

// 4. After calculating the indegree, the code initializes an empty queue `q` and pushes all the vertices with an indegree of 0 into the queue. Vertices with an indegree of 0 have no incoming edges and can be considered as starting points for the topological sort.

// 5. The code then enters a while loop that continues until the queue is empty. In each iteration of the loop, it dequeues a vertex from the front of the queue.

// 6. The dequeued vertex is then added to the result vector `ans`, which stores the topological ordering of the vertices.

// 7. Next, the code updates the indegree of each neighbor of the dequeued vertex. It does this by iterating over the neighbors of the dequeued vertex and decrementing their indegree. If the indegree of a neighbor becomes 0 after decrementing, it means that all its incoming edges have been processed, so it is added to the queue.

// 8. Finally, when the while loop finishes, the code returns the result vector `ans`, which contains the topological ordering of the vertices.

// Overall, this code uses the BFS algorithm to perform a topological sort on a directed acyclic graph. It starts by creating an adjacency list and calculating the indegree of each vertex. Then, it uses a queue to process the vertices with an indegree of 0 and updates the indegree of their neighbors. The process continues until all vertices have been processed, resulting in a topological ordering of the vertices.