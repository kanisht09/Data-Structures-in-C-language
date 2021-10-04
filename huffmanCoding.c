#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mx 100

long long int no_of_bits_after_compression = 0;
typedef struct node
{
    char data;
    int fre;
    struct node *left, *right;
} node;

typedef struct heap
{
    int size;
    int capacity;
    node **array;
} heap;

node *newNode(char data, int freq)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->fre = freq;
    return temp;
}

heap *createMinHeap(int capacity)
{
    heap *minHeap = (heap *)malloc(sizeof(heap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (node **)malloc(minHeap->capacity * sizeof(node *));
    return minHeap;
}

void swapMinHeapNode(node **a, node **b)
{
    node *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(heap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->fre < minHeap->array[smallest]->fre)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->fre < minHeap->array[smallest]->fre)
        smallest = right;
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
int isSizeOne(heap *minHeap)
{
    return (minHeap->size == 1);
}
node *extractMin(heap *minHeap)
{
    node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
void insertMinHeap(heap *minHeap, node *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->fre < minHeap->array[(i - 1) / 2]->fre)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(heap *minHeap)
{

    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
int isLeaf(node *root)
{
    return !(root->left) && !(root->right);
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
heap *createAndBuildMinHeap(char *data, int *freq, int size)
{

    heap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
node *buildHuffmanTree(char *data, int *freq, int size)
{
    node *left, *right, *top;
    heap *minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->fre + right->fre);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printCodes(node *root, int arr[], int top, int *req)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, req);
    }
    if (root->right)
    {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1, req);
    }
    if (isLeaf(root))
    {

        printf("%c : ", root->data);
        no_of_bits_after_compression += top * req[(int)root->data];
        no_of_bits_after_compression += top;
        printArr(arr, top);
    }
}
void HuffmanCodes(char *data, int *freq, int size, int *req)
{
    node *root = buildHuffmanTree(data, freq, size);
    int arr[mx], top = 0;
    printCodes(root, arr, top, req);
}
int min(int x, int y)
{
    return (x < y) ? x : y;
}
int main()
{

    // here the use of file pointer is involved so dont use stdin(fflush)

    int freq[256]; // as the total no. of ASCII characters is 2^8  (8 bits)
    for (int i = 0; i < 256; i++)
        freq[i] = 0;
    int n;
    printf("Enter the number of distinct characters : \n");
    scanf("%d", &n);

    printf("%d\n", n);
    char alpha;
    int freqval;
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%c%d", &alpha, &freqval);
        int x = (int)alpha;
        freq[x] = freqval;
    }
    int total_no_characters = 0;
    int ct = 0; // stores the no. of distinct characters
    for (int i = 0; i < 256; i++)
    {
        total_no_characters += freq[i];
        if (freq[i] > 0)
            ct++;
    }
    // array of distinct characters
    char *q = (char *)malloc(ct * sizeof(char));
    int *frequency = (int *)malloc(ct * sizeof(int));
    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            char x = (char)i;
            *(q + j) = x;
            frequency[j] = freq[i];
            j++;
        }
    }
    // Calculation for fixed length coding=0;
    int no_of_bits_reqd = 0;
    int femp = ct;
    while (femp > 0)
    {
        femp >>= 1;
        no_of_bits_reqd++;
    }
    long long int bits_before_compression = total_no_characters * no_of_bits_reqd + ct * 8 + ct * no_of_bits_reqd;
    for (int i = 0; i < ct; i++)
    {
        printf("%c %d\n", q[i], freq[(int)q[i]]);
    }
    printf("\n");
    printf("No of bits required before compression : \n");
    printf("%lld\n", bits_before_compression);
    HuffmanCodes(q, frequency, ct, freq);
    no_of_bits_after_compression += ct * 8;
    printf("No of bits required after compression : \n");
    printf("%lld\n", no_of_bits_after_compression);

    return 0;
}
