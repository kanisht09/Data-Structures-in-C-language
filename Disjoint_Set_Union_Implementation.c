#include <stdio.h>
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
        int j = 0;
        for (int i = R[x]; i < R[y] + R[x]; i++)
        {
            track[x][i] = track[y][j++];
        }
        for (int i = 0; i < R[x] + R[y]; i++)
        {
            printf("%d ", track[x][i]);
        }
        printf("\n");
        par[x] += par[y];
        R[x] += R[y];
        par[y] = x;
    }
    else
    {
        int j = 0;
        for (int i = R[y]; i < R[y] + R[x]; i++)
        {
            track[y][i] = track[x][j++];
        }
        for (int i = 0; i < R[x] + R[y]; i++)
        {
            printf("%d ", track[y][i]);
        }
        printf("\n");
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
        track[i][0] = i;
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
    long long sum = 0;
    int step = 1;
    for (int i = 0; i < m; i++)
    {
        node c = getMin();
        extractMin();
        u = edges[c.wt].ff;
        v = edges[c.wt].ss;
        u = Find(u);
        v = Find(v);
        if (u != v)
        {
            printf("Step %d :\n", step);
            step++;
            Union(u, v);
            sum += c.val;
        }
    }
    printf("\nThe minimum weight of the spanning tree is : %lld\n", sum);

    return 0;
}
