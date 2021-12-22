#include <bits/stdc++.h>
using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    // cout << v << " ";
    cout <<"Dequeuing vertex  "<< v <<" from queue "<< " " << endl;

 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]){
            cout<< "putting vertex " << *i << " in recursive state "<<endl;
            DFS(*i);
        }
}
 
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
        /* Time function returns the time since the 
        Epoch(jan 1 1970). Returned time is in seconds. */
    clock_t start, end;
  
    /* Recording the starting clock tick.*/
    start = clock();
  
    // cout << "Following is Breadth First Traversal "
    //      << "(starting from vertex 2) \n";
    g.DFS(2);
    // Recording the end clock tick.
    end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
 
