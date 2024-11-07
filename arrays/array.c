#include<stdio.h>
#include<stdlib.h>
void traverse(int* arr,int n)
{
    printf("Array :- \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf ("\n");
}
int* insert_end(int* arr,int *n,int ele)
{
    (*n)++;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    arr[(*n)-1]=ele;
    return arr;
}
int* insert_beg(int* arr, int* n, int ele)
{
    (*n)++;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    for (int i = (*n)-2; i >= 0 ; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=ele;
    return arr;
}
int* insert_pos(int* arr, int* n,int ele, int pos)
{
    (*n)++;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    if (pos>(*n) || pos < 1)
    {
        printf("invalid position");
        (*n)--;
        return arr;
    }
    for (int i = (*n)-2; i >= pos-1; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=ele;
    return arr;
}
int* insert_aft_ele(int*arr,int*n,int ele,int afele)
{
    int pos=-1;
    for (int i = 0; i < (*n); i++)
    {
        if (afele == arr[i])
        {
            pos=i+1;
            break;
        }        
    }
    if (pos == -1) 
    {
        printf("Element not present in the array\n");
        return arr;
    }
    (*n)++;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    for (int i = (*n)-2; i >= pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=ele;
    return arr;
}
int* delete_beg(int*arr, int* n)
{
    if (*n <= 0)
    {
        printf("Array is already empty\n");
        return arr;
    }
    for (int i = 0; i < (*n)-1; i++)
    {
        arr[i]=arr[i+1];
    }
    (*n)--;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    return arr;
}
int* delete_end(int*arr, int* n)
{
    if (*n <= 0) {
        printf("Array is already empty\n");
        return arr;
    }
    (*n)--;
    arr = (int*)realloc(arr,(*n)*sizeof(int));
    return arr;
}
int* delete_pos(int* arr, int* n, int pos)
{
    
}
int* delete_aft_ele(int*arr,int*n,int afele)
{
    
}
int main()
{
    int n,c,ele,ci,pos,afele;
    printf("Enter the number of elements in the array \n");
    scanf("%d",&n);
    int*arr=(int *)malloc(n*sizeof(int));
    printf("enter the elements of the array \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d \n",i+1);
        scanf("%d",&arr[i]);
    }
    while (1)
    {
        printf("\n*choose from the following options to perform operations on the array* \ntraverse : 1 \ninsert element in the array : 2 \ndelete element from the array \nexit : 0\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            traverse(arr,n);
            break;
        case 2:
            printf("*choose from the following insertion operations* \ninsert at the beginning : 1 \ninsert at the end : 2 \ninsert at a position : 3 \ninsert after a element : 4 \n");
            scanf("%d",&ci);
            switch (ci)
            {
            case 1:
                printf("Enter the element to be inserted in the array \n");
                scanf("%d",&ele);
                arr = insert_beg(arr,&n,ele);
                break;
            case 2:
                printf("Enter the element to be inserted in the array \n");
                scanf("%d",&ele);
                arr = insert_end(arr,&n,ele);
                break;
            case 3:
                printf("Enter the element to be inserted in the array \n");
                scanf("%d",&ele);
                printf("Enter the position at which the element is to be placed \n");
                scanf("%d",&pos);
                arr = insert_pos(arr,&n,ele,pos);
                break;
            case 4:
                printf("Enter the element to be inserted in the array \n");
                scanf("%d",&ele);
                printf("Enter the element after which the element is to be placed \n");
                scanf("%d",&afele);
                arr = insert_aft_ele(arr,&n,ele,afele);
                break;
            }
            break;
        case 3:
            printf("*choose from the following deletion operations* \ndelete at the beginning : 1 \ndelete at the end : 2 \ndelete at a position : 3 \ndelete after a element : 4 \n");
            scanf("%d",&ci);
            switch (ci)
            {
            case 1:
                arr = delete_beg(arr,&n);
                break;
            case 2:
                arr = delete_end(arr,&n);
                break;
            case 3:
                printf("Enter the position at which the element is to be deleted \n");
                scanf("%d",&pos);
                arr = delete_pos(arr,&n,pos);
                break;
            case 4:
                printf("Enter the element after which the element is to be deleted \n");
                scanf("%d",&afele);
                arr = delete_aft_ele(arr,&n,afele);
                break;
            }
            break;
        case 0:
            free(arr);
            exit(0);
            break;
        default:
            printf("Invalid input \n");
            break;
        }
    }
    
    return 0;
}