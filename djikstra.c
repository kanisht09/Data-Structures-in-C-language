#include <stdio.h>

// contains implementation of priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> i.e min heap of pair of C++ in C
#include "heap.h"

#include <stdlib.h>

// distance array
int dis[100005];
int path[100005];
int temp[10000005];
const int inf = INT_MAX;

typedef struct Node
{
    int dest;
    int wt;
    struct Node *next;
} Node;
typedef struct adj
{
    Node *head;
} adj;
typedef struct Graph
{
    int V;
    adj *lst;
} Graph;
Node *adjnode(int dest, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->wt = weight;
    newNode->next = NULL;
    return newNode;
}
Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->lst = (adj *)malloc(V * sizeof(adj));
    for (int i = 0; i < V; ++i)
        graph->lst[i].head = NULL;
    return graph;
}
void addEdge(Graph *graph, int src, int dest, int weight)
{
    Node *newNode = adjnode(dest, weight);
    newNode->next = graph->lst[src].head;
    graph->lst[src].head = newNode;
}

int main()
{

    int n, e;
    printf("Enter the number of nodes and edges in the graph :\n");
    scanf("%d%d", &n, &e);
    printf("Enter the edges and their corresponding weights :\n");
    int notok = 0;
    int u, v, wt;
    Graph *vt = createGraph(e);

    for (int i = 0; i < e; i++)
    {
        scanf("%d%d%d", &u, &v, &wt);
        if (wt >= 0)
        {
            addEdge(vt, u, v, wt);
        }
        else
        {
            notok = 1;
            break;
        }
    }
    if (notok)
    {
        printf("Negative edge detected , so Djikstra might not give correct shortest distance.\n");
    }
    else
    {
        int src;
        printf("Enter the source vertex :\n");
        scanf("%d", &src);
        for (int i = 0; i <= n; i++)
        {
            path[i] = -1;
            dis[i] = inf;
        }
        dis[src] = 0;
        enqueue(dis[src], src);
        // here size is the size of priority_queue in the header file heap.h
        while (size != 0)
        {
            node data = getMin();
            int curdis = data.val;
            int curnode = data.wt;
            extractMin();
            if (curdis != dis[curnode])
            {
                continue;
            }
            Node *nx = vt->lst[curnode].head;
            while (nx != NULL)
            {
                int rw = nx->wt;
                if (dis[nx->dest] > rw + curdis)
                {
                    path[nx->dest] = curnode;
                    dis[nx->dest] = rw + curdis;
                    enqueue(dis[nx->dest], nx->dest);
                }
                nx = nx->next;
            }
        }
        printf("The distance of nodes from the source node\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", dis[i]);
        }
        printf("\nEnter the destination node : \n");
        int desty;
        scanf("%d", &desty);
        if (dis[desty] == inf)
        {
            printf("The %d th node is not reachable from the source node i.e %d.\n", desty, src);
        }
        else
        {
            int ix = 0;
            for (int vz = desty; vz != src; vz = path[vz])
            {
                temp[ix++] = vz;
            }
            temp[ix++] = src;
            printf("The shortest path from source to destination is : \n");
            for (int i = ix - 1; i >= 0; i--)
                printf("%d ", temp[i]);
            printf("\n");
        }
    }
    return 0;
}
