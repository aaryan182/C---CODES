#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &s , unordered_map<int, list<int> > &adj){
    visited[node] = 1;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour])
            topoSort(neighbour, visited, s , adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v)  {
    // create adj list 
    unordered_map<int, list<int> > adj;
    for(int i = 0; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topological sort util function for all components
    vector<bool> visited(v, false);
    stack<int> s;
    for(int i = 0; i< v;i++){
        if(!visited[i])
            topoSort(i, visited, s, adj);
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1}, 
        {1, 2},
        {2, 3},
        {2, 4}
    };
    vector<int> result = topologicalSort(edges, 5);
    for(int i : result){
        cout << i << " ";
    }
    return 0;
}


// This code is used to perform a topological sort on a directed graph. Topological sort is an ordering of the nodes in a directed graph such that for every directed edge (u, v), node u comes before node v in the ordering.

// The code starts with a function `topoSort` which takes in a node, a vector of visited nodes, a stack to store the sorted nodes, and an adjacency list representing the graph. 

// The function marks the current node as visited and then iterates over all its neighbors. If a neighbor has not been visited yet, the function recursively calls itself on that neighbor. This ensures that all the nodes reachable from the current node are visited before it is added to the stack.

// After the `topoSort` function, there is a `topologicalSort` function which takes in a vector of edges and the number of nodes in the graph. 

// First, it creates an adjacency list from the given edges. It iterates over each edge and adds the second node of the edge to the adjacency list of the first node.

// Then, it initializes a vector of visited nodes and a stack to store the sorted nodes. It iterates over all the nodes in the graph and if a node has not been visited yet, it calls the `topoSort` function on that node.

// Finally, it creates a vector `ans` to store the sorted nodes and pops nodes from the stack and adds them to `ans` until the stack is empty. The vector `ans` is then returned as the result of the topological sort.