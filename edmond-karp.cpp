
#include <iostream>
#include <string.h>
#include<climits>
#include <queue>
using namespace std;
bool edmondkarp(int s, int t, int parent[] , int edgraph[][6])
{
    bool visited[6];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < 6; v++)
        {
            if (visited[v] == false && edgraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
 
void eka( int s, int t, int graph[6][6])
{
    int u, v;
    int parent[6];
    int max_flow = 0;
    int count=0;
    while (edmondkarp(s, t, parent , graph))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
        count++;
        cout<<endl;
        cout<<"Path flow on level "<<count<<"-"<<path_flow;
        max_flow += path_flow;
    }
    cout<<"\n\nMaximum Path Flow will be = "<<max_flow;
}
int main()
{
    int graph[6][6] = { {0, 7, 10, 0, 0, 0},
                        {0, 0, 1, 3, 5, 0},
                        {0, 0, 0, 4, 0, 7},
                        {0, 0, 0, 0, 3, 2},
                        {0, 0, 0, 0, 0, 2},
                        {0, 0, 0, 0, 0, 0},             
                      }; 
     eka( 1, 5, graph);
}