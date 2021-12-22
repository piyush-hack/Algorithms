//Bellman Ford shortest path algorithm in c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

struct Edge
{
    // edge is created with this struct. 
    int origin;
    int destination;
    int weight;
};

// this struct is representing a connected, directed and weighted graph
struct Graph
{
    int V, E;

    struct Edge *edge;
};

struct Graph *generate_graph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->V = V; //giving values to struct element 

    graph->E = E;

    graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
    //Generating Edge  inside Graph 
    return graph;
}

void result(int dist[], int n)
{
    // This function prints the final solution
    printf("\nVertex\tDistance from origin Vertex\n");
    int i;

    for (i = 0; i < n; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void bellman_ford(struct Graph *graph, int origin)
{
    int V = graph->V;

    int E = graph->E;

    int StoreDistance[V];

    int i, j;

    // This is initial step that we know , we initialize all distance to infinity except origin.
    // We assign origin distance as 0(zero)

    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;

    StoreDistance[origin] = 0;

    //The shortest path of graph that contain V vertices, never contain "V-1" edges. So we do here "V-1" relaxations
    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].origin;

            int v = graph->edge[j].destination;

            int weight = graph->edge[j].weight;

            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }


    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].origin;

        int v = graph->edge[i].destination;

        int weight = graph->edge[i].weight;

        if (StoreDistance[u] + weight < StoreDistance[v])
            printf(" graph have negative edge cycle\n");
    }

    result(StoreDistance, V);

    return;
}

int main()
{
    int V, E, S; //V = no.of Vertices, E = no.of Edges, S is origin vertex

    printf("Vertices in your graph\n");
    scanf("%d", &V);

    printf("edges in the graph\n");
    scanf("%d", &E);

    printf("starting vertex number\n");
    scanf("%d", &S);

    struct Graph *graph = generate_graph(V, E); //calling the function to allocate space to these many vertices and edges

    int i;
    for (i = 0; i < E; i++)
    {
        printf("\nOrigin, Destination, Weight(may be negative) of edge %d  \n", i + 1);
        scanf("%d", &graph->edge[i].origin);
        scanf("%d", &graph->edge[i].destination);
        scanf("%d", &graph->edge[i].weight);
    }

    clock_t t;
    t = clock();
    bellman_ford(graph, S);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("\nbellman_ford took %f seconds to execute \n", time_taken);
  

    return 0;
}
