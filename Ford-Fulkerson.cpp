#include <iostream>
#include <string.h>
using namespace std;
#define N 7
#define INF 9999999
// flow network
int Flow[N][N];
// visited array
bool visited[N];
// original flow network graph shown in the above example
//0 1  2  3  4 5  6

int fordFulkerson(int s, int t, int minimum , int graph[7][7]) {
    visited[s] = true;
    // if source and sink is same
    if (s == t)
        return minimum;
    for (int i = 0; i < N; i++) {
        int flow_capacity = graph[s][i] - Flow[s][i];
        if (!visited[i] && flow_capacity > 0) {
            // find min capacity in fordFulkerson path
            if (int sent = fordFulkerson (i, t, min (minimum, flow_capacity) , graph)) {
                // adjust the capacity
                Flow[s][i] += sent;
                Flow[i][s] -= sent;
                
                return sent;
            }
        }
    }
    return false;
}
int main() {
    // initialize initial flow capacity 0
    memset(Flow, 0, sizeof(Flow));
    // initialize visited array false initially
    memset(visited, 0, sizeof(visited));
    int s = 5;
    int t = 6;
    int max_flow = 0;
    int graph[N][N] = {
        { 0, 5, 4, 0, 0, 0, 0 }, //0
        { 0, 0, 0, 0, 0, 0, 4 }, //1
        { 0, 0, 0, 3, 0, 0, 6 }, //2
        { 0, 0, 0, 0, 5, 0, 0 }, //3
        { 0, 0, 0, 0, 0, 0, 8 }, //4
        { 6, 0, 0, 2, 0, 0, 0 }, //5
        { 0, 0, 0, 0, 0, 0, 0 }, //6
        };
    // while ther is augmenting path , from s and t
    // with positive flow capacity
    int count=0;
    while (int sent = fordFulkerson(s, t, INF , graph)) {
        max_flow += sent;
        // reset visited array , for searching next path
        count++;
        cout<<endl;
        cout<<"Path_flow at level "<<count<<":"<<max_flow;

        memset(visited, 0, sizeof(visited));
    }
    cout<<endl;
    cout << "The max flow from node 5 to sink node 6 is " << max_flow;
    cout << endl;
}