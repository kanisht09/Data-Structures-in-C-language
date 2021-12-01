#include <stdio.h>
#include <malloc.h>
#include "heap.h"
#define ll long long
typedef struct pair
{
    int ff, ss;
} pair;

int par[1001];
int R[1001];
pair edges[10000005];
int track[1001][1001];
// DSU with path compression and Rank by Union
int Find(int x)
{
    if (par[x] < 0)
        return x;
    return par[x] = Find(par[x]);
}
void Union(int x, int y)
{
    if (R[x] > R[y])
    {

        par[x] += par[y];
        R[x] += R[y];
        par[y] = x;
    }
    else
    {

        par[y] += par[x];
        R[y] += R[x];
        par[x] = y;
    }
}
int main()
{

    int n, m;
    printf("Enter the number of nodes and edges.\n");
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        R[i] = 1;
        par[i] = -1;
    }
    int u, v, wt;
    printf("Enter the edges along with their weights.\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &wt);
        edges[i].ff = u;
        edges[i].ss = v;
        enqueue(wt, i);
    }
    int *vis = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    long long sum = 0;
    int step = 1;
    printf("The path is : \n");
    for (int i = 0; i < m; i++)
    {
        node c = getMin();
        extractMin();
        u = edges[c.wt].ff;
        v = edges[c.wt].ss;
        int xu = u;
        int xv = v;
        u = Find(u);
        v = Find(v);
        if (u != v)
        {
            Union(u, v);
            sum += c.val;

            printf("%d %d %d \n", xu, xv, c.val);
        }
    }
    printf("\nThe minimum weight of the spanning tree is : %lld\n", sum);

    return 0;
}
