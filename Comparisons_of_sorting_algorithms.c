#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// 10 input data (size of input) 
// 5 sorting algorithms (0-4) [indexing] 
// 3 cases (min,max,average)

int data[10][5][3];
int max(int x,int y)
{
    return (x>y)?x:y;
}
int min(int x,int y)
{
    return (x<y)?x:y;
}
void print_(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
}
int data_index=0;
int factorial=0;
// int sum=0;
void generator(int i,int *p,int n)
{
    if(i==n)
    {
    factorial++;

        for(int algos=0;algos<5;algos++)
        {
            int *temp=(int*)malloc(n*sizeof(int));
            for(int j=0;j<n;j++)
            {
                temp[j]=p[j];
            }
            int number_of_comparisons=0;
            switch (algos)
            {
                case 0:
                {
                    number_of_comparisons=impBubbleSort(temp,n);
                    data[data_index][algos][0]=max(number_of_comparisons,data[data_index][algos][0]);
                    data[data_index][algos][1]=min(number_of_comparisons,data[data_index][algos][1]);
                    data[data_index][algos][2]+=number_of_comparisons;
                    break;
                }
                case 1:
                    {
                        number_of_comparisons=insertionSort(temp,n);
                    data[data_index][algos][0]=max(number_of_comparisons,data[data_index][algos][0]);
                    data[data_index][algos][1]=min(number_of_comparisons,data[data_index][algos][1]);
                    data[data_index][algos][2]+=number_of_comparisons;
                    break;
                    }
                case 2:{
                    number_of_comparisons=heapSort(temp,n);
                    data[data_index][algos][0]=max(number_of_comparisons,data[data_index][algos][0]);
                    data[data_index][algos][1]=min(number_of_comparisons,data[data_index][algos][1]);
                    data[data_index][algos][2]+=number_of_comparisons;
                    break;
                }
                case 3:{
                    number_of_comparisons=mergeSort(temp,n);
                    data[data_index][algos][0]=max(number_of_comparisons,data[data_index][algos][0]);
                    data[data_index][algos][1]=min(number_of_comparisons,data[data_index][algos][1]);
                    data[data_index][algos][2]+=number_of_comparisons;
                    break;
                }
                case 4:{
                    number_of_comparisons=randQuickSort(temp,n);
                    data[data_index][algos][0]=max(number_of_comparisons,data[data_index][algos][0]);
                    data[data_index][algos][1]=min(number_of_comparisons,data[data_index][algos][1]);
                    data[data_index][algos][2]+=number_of_comparisons;
                    break;
                }
                default:
                    break;
            }
            
        }

        return;
    }
    for(int j=i;j<n;j++)
    {
        swap(&p[i],&p[j]);
        generator(i+1,p,n);
        swap(&p[i],&p[j]);
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    

     for(int dataIndex=0;dataIndex<10;dataIndex++)
     {
        for(int algos=0;algos<5;algos++)
        {
            for(int cases=0;cases<3;cases++)
            {
                if(cases==0 || cases==2)
                    data[dataIndex][algos][cases]=0;
                else
                    data[dataIndex][algos][cases]=INT_MAX;
            }
        }
     }
    for(int dataIndex=0;dataIndex<1;dataIndex++)
    {
        factorial=0;
        data_index=dataIndex;
        printf("Data %d : \n",dataIndex+1);
        int n;
        scanf("%d",&n);
        int *p=(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
        }
        generator(0,p,n);
        for(int algos=0;algos<5;algos++)
        {
            switch (algos)
            {
            case 0:
            {
                printf("Improved bubble sort : \n");
                break;
            }
            case 1:
            {
                printf("Insertion sort : \n");
                break;
            }
            case 2:
            {
                printf("Heap sort :\n");
                break;
            }
            case 3:
            {
                printf("Merge sort :\n");
                break;
                }
            case 4:
            {
                printf("Randomised quick sort :\n");
                break;
            }
            default:
                break;
            }
            for(int cases=0;cases<3;cases++)
            {
                switch (cases)
                {
                case 0:
                {
                    printf("Worst case : ");
                printf("%d \n",data[dataIndex][algos][cases]);
                    break;
                }
                case 1:
                {
                    printf("Best case : ");
                printf("%d\n",data[dataIndex][algos][cases]);
                    break;
                }
                case 2:
                {
                    printf("Average case : ");
                    data[dataIndex][algos][cases]=data[dataIndex][algos][cases]/factorial;
                printf("%d\n",data[dataIndex][algos][cases]);

                    break;
                }
                default:
                    break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;

}
