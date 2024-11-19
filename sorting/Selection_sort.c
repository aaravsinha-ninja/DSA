#include<stdio.h>
#include<stdlib.h>
int* Selection_sort(int* arr,int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int flag=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[flag]>arr[j])
            {
                flag=j;
            }
            
        }
        if (flag!=i)
        {
            int temp=arr[i];
            arr[i]=arr[flag];
            arr[flag]=temp;
        }
        
    }
    
    return arr;
}
int main()
{
    return 0;
}