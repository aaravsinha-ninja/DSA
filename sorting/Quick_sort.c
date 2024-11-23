#include <stdio.h>
#include <stdlib.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void swap(int A[],int i,int j)
{
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}
int partition(int A[], int low, int high)
{
    int piviot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    do
    {
        while (A[i]<=piviot)
        {
            i++;
        }
        while (A[j]>piviot)
        {
            j--;
        }
        if (i<j)
        {
            swap(A,i,j);
        }
        
    } while (i<j);
    swap(A,low,j);
    return j;
}
void Quick_sort(int A[], int low, int high)
{
    int partition_index;
    if (low < high)
    {
        partition_index = partition(A, low, high);
        Quick_sort(A,low,partition_index-1);
        Quick_sort(A,partition_index+1,high);
    }
}
int main()
{
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    int n = 7;
    printArray(A, n);
    Quick_sort(A, 0, n-1);
    printArray(A, n);
    return 0;
}