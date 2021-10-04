#define INF 1e9
// 0 based indexing

typedef struct node
{
    int val;
    int wt;
} node;
int maxsize = 1000005;
node h[1000005];
int size = 0;
int parent(int i)
{
    return (i - 1) / 2;
}
int leftchild(int i)
{
    return 2 * i + 1;
}
int rightchild(int i)
{
    return 2 * i + 2;
}
// upon insertion shift up is required to regain the heap structure
int comp(node x, node y)
{
    if (x.val < y.val)
        return 1;
    if (x.val == y.val)
    {
        if (x.wt < y.wt)
            return 1;
    }
    return 0;
}
void shiftup(int i)
{
    while (i != 0 && comp(h[i], h[parent(i)]))
    {
        int x = h[i].val;
        int y = h[i].wt;
        h[i].val = h[parent(i)].val;
        h[i].wt = h[parent(i)].wt;
        h[parent(i)].val = x;
        h[parent(i)].wt = y;
        i = parent(i);
    }
}
// upon deletion or upon extraction of top value
// This is the heapify operation
void shiftdown(int i)
{
    int minindex = i;
    int l = leftchild(i);
    int r = rightchild(i);
    if (l < size && comp(h[l], h[minindex]))
    {
        minindex = l;
    }
    if (r < size && comp(h[r], h[minindex]))
    {
        minindex = r;
    }
    if (i != minindex)
    {
        int x = h[i].val;
        int y = h[i].wt;
        h[i].val = h[minindex].val;
        h[i].wt = h[minindex].wt;
        h[minindex].val = x;
        h[minindex].wt = y;
        shiftdown(minindex);
    }
}

void enqueue(int x, int y)
{
    if (size == maxsize)
    {
        printf("size is full\n");
        return;
    }
    else
    {
        size++;
        h[size - 1].val = x;
        h[size - 1].wt = y;
        shiftup(size - 1);
    }
}
node getMin()
{
    node x;
    x.val = h[0].val;
    x.wt = h[0].wt;
    return x;
}
int extractMin()
{
    if (size <= 0)
    {
        return INF;
    }
    if (size == 1)
    {
        size--;
        return h[0].val;
    }
    int result = h[0].val;
    h[0].val = h[size - 1].val;
    h[0].wt = h[size - 1].wt;
    size--;
    shiftdown(0);
    return result;
}
void Remove(int i)
{
    h[i].val = -INF;
    h[i].wt = INF;
    shiftup(i);
    extractMin();
}
void decreaseKey(int i, int nv, int y)
{
    h[i].val = nv;
    h[i].wt = y;
    shiftup(i);
}