#include<stdio.h>
#include<stdlib.h>

int* insert_sort(int* arr, int* n, int num)
{
    (*n)++;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    int i;
    for (i = (*n) - 2; i >= 0 && arr[i] > num; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = num;
    return arr;
}
int main()
{
    return 0;
}