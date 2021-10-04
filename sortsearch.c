#include<stdio.h>
#include "sorting.h"
#include <stdlib.h>

void sortMenu()
{
    printf("Sorting Menu :\n");
    printf("Press 1 for Selection sort\n");
    printf("Press 2 for Bubble sort\n");
    printf("Press 3 for Insertion sort\n");
}

void searchMenu()
{
    printf("Searching Menu :\n");
    printf("Press 1 for Linear Search.\n");
    printf("Press 2 for Binary Search.\n");
    printf("Press 3 for Interpolation Search.\n");
}

void print_(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
}

int main()
{

    printf("Sorting and Searching\n");
    int f=1;
    int ct=0;
    while(f)
    {
        
        sortMenu();
        int choice;
        scanf("%d",&choice);
        int n;
        printf("Enter the size of the array\n");
        scanf("%d",&n);
        int *p=(int*)malloc(n*sizeof(int));
        printf("Enter the elements of the array :\n");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
        }
        printf("The elements of the array before sorting : \n");
        print_(p,n);
        int g=0;
        switch (choice)
        {
            case 1:
            {
                int ct=selectionSort(p,n);
                printf("The number of comparisons required is %d \n",ct);
                break;
            }
            case 2:
            {
                int ct=bubbleSort(p,n);
                printf("The number of comparisons required is %d \n",ct);
                break;
            }
            case 3:
            {
                int ct=insertionSort(p,n);
                printf("The number of comparisons required is %d \n",ct);
                break;
            }
            default:
            {
                g=1;
                printf("Invalid choice \n");
                break;
            }
        }  
        int y;
        printf("Do you want to continue : press 0 \n");
        scanf("%d",&y);             
        if(g || !y)
        {
            continue;
        }
        else
        {
                searchMenu();
                int choice;
                scanf("%d",&choice);
                int n;
                printf("Enter the size of the array\n");
                scanf("%d",&n);
                int *p=(int*)malloc(n*sizeof(int));
                printf("Enter the elements of the array :\n");
                for(int i=0;i<n;i++)
                {
                    scanf("%d",&p[i]);
                }
                printf("The elements of the array are : \n");
                print_(p,n);
                int key;
                printf("Enter the value you want to search. \n");
                scanf("%d",&key);
                int g=0;
                switch (choice)
                {
                    case 1:
                    {
                        linearSearch(p,n,key);
                        break;
                    }
                    case 2:{
                        int z=isSorted(p,n);
                        if(!z)
                        {
                            sortMenu();
                            int ch;
                            scanf("%d",&ch);
                            int t=1;
                            while(t)
                            {
                                switch(ch)
                                {
                                    case 1:
                                    {
                                        t=0;
                                        selectionSort(p,n);
                                        break;
                                    }
                                    case 2:
                                    {
                                        t=0;
                                        bubbleSort(p,n);
                                        break;
                                    }
                                    case 3:
                                    {
                                        t=0;
                                        insertionSort(p,n);
                                        break;
                                    }
                                    default:
                                    {
                                        printf("Invalid choice\n");
                                        break;
                                    }
                                }
                            }
                        }
                        binarySearch(p,n,key);
                        break;
                    }
                    case 3:
                    {
                        int z=isSorted(p,n);
                        if(!z)
                        {
                            sortMenu();
                            int ch;
                            scanf("%d",&ch);
                            int t=1;
                            while(t)
                            {
                                switch(ch)
                                {
                                    case 1:
                                    {
                                        t=0;
                                        selectionSort(p,n);
                                        break;
                                    }
                                    case 2:
                                    {
                                        t=0;
                                        bubbleSort(p,n);
                                        break;
                                    }
                                    case 3:
                                    {
                                        t=0;
                                        insertionSort(p,n);
                                        break;
                                    }
                                    default:
                                    {
                                        printf("Invalid choice\n");
                                        break;
                                    }
                                }
                            }
                        }
                        int xz=interPolationSearch(p,n,key);
                        if(xz==-1)
                        {
                          printf("The key is missing. \n");
                        }
                        else{
                            printf("The key is found at the index %d \n",xz);
                            printf("The number of comparisons required is %d\n",tracker);
                        }
                        break;
                    }
                    default:
                    {
                        g=1;
                        printf("Invalid choice \n");
                        break;
                    }
                }  
                 int y;
                printf("Do you want to continue : press 0 \n");
                scanf("%d",&y);             
                if(g || !y)
                {
                    continue;
                }
                else
                {
                    f=0;
                }
        }


    }
    return 0;
}