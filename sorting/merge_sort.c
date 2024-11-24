#include<stdio.h>
#include<stdlib.h>
void merge_sort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = left+(right - left )/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int main()
{
    return 0;
}