#include <stdio.h>
#include <stdlib.h>
void print1(int brr[], int brr_size)
{
    // int brr_size = sizeof(brr) / sizeof(brr[0]);
    printf("\n");
    for (int i = 0; i < brr_size; i++)
        printf("%d ", brr[i]);
}
int print2(int brr[])
{
    int i;
    int crr[10];
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        crr[i] = brr[i];
        printf("%d ", brr[i]);
    }
    return crr;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int *p, *q;
    int i;
    printf("\nAddress %p is : %d", (void *)p, *p);
    print1(arr, arr_size);
    q = print2(arr);
    for (i = 0; i < 10; i++)
        printf("\nAddress %p is : %d", (void *)q + i, *(q + i));
    return 0;
}