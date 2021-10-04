int max(int x, int y)
{
    return (x > y) ? x : y;
}
int min(int x, int y)
{
    return (x < y) ? x : y;
}
int tracker = 0;
int ct = 0;
void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}
void count_sort(int *p, int n)
{
    int *c = (int *)malloc(n * sizeof(int));
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, p[i]);
    }
    maxi++;
    int *q = (int *)calloc(maxi, sizeof(int));
    for (int i = 0; i < n; i++)
        q[p[i]]++;

    for (int i = 1; i < maxi; i++)
        q[i] += q[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        q[p[i]]--;
        c[q[p[i]]] = p[i];
    }
    for (int i = 0; i < n; i++)
        p[i] = c[i];
}
void radix_sort(int *p, int n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, p[i]);
    }
    int mxno_digit = 0;
    while (maxi > 0)
    {
        mxno_digit++;
        maxi /= 10;
    }
    int temp = 1;
    for (int i = 0; i < mxno_digit; i++)
    {
        int *c = (int *)malloc(n * sizeof(int));
        int *q = (int *)calloc(10, sizeof(int));
        int val = 0;
        for (int j = 0; j < n; j++)
        {
            val = p[j] / temp;
            q[(val % 10)]++;
        }
        for (int j = 1; j < 10; j++)
            q[j] += q[j - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            val = p[j] / temp;
            q[(val % 10)]--;
            c[q[(val % 10)]] = p[j];
        }
        for (int j = 0; j < n; j++)
            p[j] = c[j];
        temp *= 10;
    }
}
void cocktailshackersort(int *p, int n)
{
    int start = 0;
    int end = n - 1;
    int swapb = 1;
    while (swapb)
    {
        swapb = 0;
        for (int i = start; i < end; i++)
        {
            if (p[i] > p[i + 1])
            {
                swapb = 1;
                swap(&p[i], &p[i + 1]);
            }
        }
        end--;
        if (!swapb)
        {
            break;
        }
        for (int i = end - 1; i >= start; i--)
        {
            if (p[i] > p[i + 1])
            {
                swapb = 1;
                swap(&p[i], &p[i + 1]);
            }
        }
        start++;
    }
}
void heapify(int i, int *p, int n)
{
    int l = 2 * i + 1;  // 0-based 
    int r = 2 * i + 2;
    int s = i;
    if (l < n && p[l] > p[s])
    {
        s = l;
        ct++;
    }
    if (r < n && p[r] > p[s])
    {
        s = r;
        ct++;
    }
    if (s != i)
    {
        ct++;
        swap(p + i, p + s);
        heapify(s, p, n);
    }
}
int heapSort(int *p, int n)
{
    ct = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(i, p, n);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(p, p + i);
        heapify(0, p, i);
    }
    return ct;
}
void merge(int *p, int l, int m, int r)
{
    if (p[m] <= p[m + 1])
    {
        ct++;
        return;
    }
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (j = 0; j < n2; j++)
        R[j] = p[m + j + 1];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {

        if (L[i] <= R[j])
        {
            ct++;
            p[k] = L[i];
            i++;
        }
        else
        {
            ct++;
            p[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        ct++;
        p[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        ct++;
        p[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *p, int l, int r)
{
    if (l < r)
    {
        int mid = l + ((r - l) / 2);
        mergesort(p, l, mid);
        mergesort(p, mid + 1, r);
        merge(p, l, mid, r);
    }
}
int mergeSort(int *p, int n)
{
    ct = 0;
    mergesort(p, 0, n - 1);
    return ct;
}
int partition(int *p, int low, int high)
{
    int pivot = p[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (p[j] <= pivot)
        {
            i++;
            swap(&p[i], &p[j]);
        }
        ct++;
    }
    swap(&p[i + 1], &p[high]);
    return (i + 1);
}
int randomPartition(int *p, int low, int high)
{
    int random = low + rand() % (high - low);
    swap(&p[random], &p[high]);
    return partition(p, low, high);
}
void quickSort(int *p, int low, int high)
{
    if (low < high)
    {
        int pi = randomPartition(p, low, high);
        quickSort(p, low, pi - 1);
        quickSort(p, pi + 1, high);
    }
}

int randQuickSort(int *p, int n)
{
    ct = 0;
    quickSort(p, 0, n - 1);
    return ct;
}
int selectionSort(int *p, int n)
{
    ct = 0;
    int i, j;
    int min_ind = 0;
    for (i = 0; i < n - 1; i++)
    {
        min_ind = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j] < p[min_ind])
            {
                ct++;
                min_ind = j;
            }
        }
        swap(&p[min_ind], &p[i]);
    }
}
int bubbleSort(int *p, int n)
{
    ct = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                swap(p + j, p + j + 1);
                ct++;
            }
        }
    }
    return ct;
}
int insertionSort(int *p, int n)
{
    ct = 0;
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        int key = *(p + i);
        int j = i - 1;
        temp = 0;
        while (j >= 0 && *(p + j) > key)
        {
            temp = 1;
            ct++;
            *(p + j + 1) = *(p + j);
            j -= 1;
        }
        if (!temp)
            ct++;
        *(p + j + 1) = key;
    }
    return ct;
}
void linearSearch(int *p, int n, int key)
{
    int ft = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == key)
        {
            ft++;
        }
    }
    if (ft != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i] == key)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("The number of comparisons required is %d \n", n);
    }
    else
    {
        printf("The key is not present.\n");
    }
}
int isSorted(int *p, int n)
{

    for (int i = 1; i < n; i++)
    {
        if (p[i] < p[i - 1])
            return 0;
    }
    return 1;
}
void binarySearch(int *p, int n, int key)
{
    int low = 0;
    int high = n;
    int ft = 0;
    while (low < high)
    {
        ft++;
        int mid = (low + high) / 2;

        if (p[mid] >= key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    ft++;
    if (p[low] == key)
    {
        printf("The key is found at the index %d \n", low);
        printf("The number of comparisons required is %d\n", ft);
    }
    else
    {

        printf("The key is missing. \n");
    }
}
int interPolationSearch(int *p, int n, int key)
{
    tracker = 0;
    int low = 0;
    int high = n - 1;
    int ft = 0;
    while ((p[low] != p[high]) && (key <= p[high]) && (key >= p[low]))
    {
        ft++;
        int pos = low + (((high - low) / (p[high] - p[low])) * (key - p[low]));
        if (p[pos] == key)
        {
            tracker = ft;
            return pos;
        }
        if (p[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}
