//DIJKSHTRA ALGORITHM

# include <stdio.h>
# include <conio.h>
#include <time.h>


# define LARGEST 100000 // 100000 is LARGEST
# define MAX 10

void algo_dijikstra(int G[MAX][MAX], int n, int startnode); //algo function

void main()
{
    int G[MAX][MAX], i, j, n, u;

    printf("\n VERTICES in your graph - ");
    scanf("%d", &n);
    printf("\n adjacency matrix of your graph - \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("\n\tStarting Node -  ");
    scanf("%d", &u);

    clock_t t;
    t = clock();

    algo_dijikstra(G, n, u);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("\nalgo_dijikstra took %f seconds to execute \n", time_taken);
  

    getch();
}

void algo_dijikstra(int G[MAX][MAX], int n, int startnode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = LARGEST;
            else
                cost[i][j] = G[i][j];

    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = LARGEST;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != startnode)
        {
           
            printf("\nDistance of %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            do
            {
                j = pred[j];
                printf(" <-%d", j);
            } while (j != startnode);
        }
}
