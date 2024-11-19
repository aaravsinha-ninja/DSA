#include<stdio.h>
#include<stdlib.h>
int sum_ele(int*arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum >= 10)
    {
        while (1)
        {
            if (sum>1000)
            {
                return -999;
            }
            if (sum < 100)
            {
                sum = (sum%10)+((sum%100)/10);
            }
            else if (sum < 1000)
            {
                sum = (sum%10)+((sum%100)/10)+(((sum%1000)/100)/10);
            }
            if (sum < 10)
            {
                return sum;
            }
               
        }
        
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum = sum_ele(arr,n);
    printf("sum %d", sum);
    return 0;
}