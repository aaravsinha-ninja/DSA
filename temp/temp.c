<<<<<<< Updated upstream
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
=======
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
>>>>>>> Stashed changes
}