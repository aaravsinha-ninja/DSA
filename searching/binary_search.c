#include<stdio.h>
#include<stdlib.h>
int binary_search(int A[],int left,int right,int x)
{
    while (left < right)
    {
        int mid=left+(right-left)/2;
        if (A[mid]==x)
        {
            return mid;
        }
        else if(A[mid]<x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}
int main()
{
    return 0;
}