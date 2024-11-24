#include<stdio.h>
#include<stdlib.h>
void swap(int A[],int i,int j)
{
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}
void heapify(int A[],int n,int i)
{
    int largest = i;
    int lc=i*2+1;
    int rc=i*2+2;
    if (lc < n && A[lc]>A[largest])
    {
        largest=lc;
    }
    if (rc < n && A[rc]>A[largest])
    {
        largest=rc;
    }
    if (largest != i)
    {
        swap(A,largest,i);
        heapify(A,n,largest);
    }    
}
void heap_sort(int A[],int n)
{
    for (int i = n/2-1; i >=0 ; i--)
    {
        heapify(A,n,i);
    }
    for (int i = n-1; i > 0; i--)
    {
        swap(A,i,0);
        heapify(A,i,0);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {9, 4, 3, 8, 10, 2, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
    return 0;
}