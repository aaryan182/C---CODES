// THERE ARE TWO METHODS TWO PRINT GRAPH ONE IS UNORDERED MAP AND SECOND IS VECTOR 


#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u , T v , bool direction){
        // direction = 0 -> undirected 
        // direction = 1 -> directed

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i : adj){
            cout << i.first << "->";
            for(auto j : i.second){
                cout << j << " ,  ";
            }
            cout << endl;
        }
    }
};



int main()
{  
   int n;
   cout<<"Enter the number of nodes : "<<endl;
   cin>>n;
   int m;
   cout<<"Enter the number of edges : "<<endl;
   cin>>m;
    
   Graph<int> g;

   for (int i = 0; i < m; i++)
   {
        int u  , v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);
   }
   // printing the graph
    g.printAdjList();
   return 0;
}


// This code is an implementation of a graph data structure using an adjacency list. 

// First, a template class `Graph` is defined. It has a public member variable `adj` which is an unordered map with keys of type `T` and values of type `list<T>`. This map represents the adjacency list of the graph, where each key represents a vertex and the corresponding value is a list of vertices that are adjacent to it.

// The `addEdge` function is used to add an edge between two vertices `u` and `v`. It takes two parameters `u` and `v` of type `T` representing the vertices, and a boolean parameter `direction` which determines whether the edge is directed or undirected. If `direction` is 0, the edge is undirected and both vertices are added to each other's adjacency list. If `direction` is 1, the edge is directed and only `v` is added to the adjacency list of `u`.

// The `printAdjList` function is used to print the adjacency list of the graph. It iterates over each key-value pair in the `adj` map and prints the key followed by an arrow (`->`). Then, it iterates over each element in the value (which is a list) and prints it followed by a comma and a space. Finally, it prints a new line.

// In the `main` function, the user is prompted to enter the number of nodes and edges in the graph. Then, an instance of the `Graph` class is created with `int` as the template parameter. 

// A loop is used to read the edges from the user and add them to the graph using the `addEdge` function. The loop runs `m` times, where `m` is the number of edges entered by the user. For each iteration, the user is prompted to enter two integers representing the vertices of an edge, and the `addEdge` function is called with these vertices and `0` as the direction parameter.

// Finally, the `printAdjList` function is called to print the adjacency list of the graph.

// Overall, this code allows the user to create a graph by entering the number of nodes and edges, and then view the adjacency list representation of the graph.