#include<stdio.h>
#include<stdlib.h>
int* bubble_sort(int*arr,int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int flag=0;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag++;
            }
            
        }
        if (flag==0)
        {
            break;
        }
        
    }
    return arr;
}
int main()
{
    return 0;
}