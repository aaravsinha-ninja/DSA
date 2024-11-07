#include<stdio.h>
#include<stdlib.h>

void traverse(int *arr,int size)
{
    printf ("Array:\n");
    for (int i=0;i<size;i++)
    {
        printf ("%d",arr[i]);
    }
    printf ("\n");
}
int *insert_end(int *arr,int *size,int element)
{
    (*size)++;
    arr=(int*)realloc(arr,(*size)*sizeof(int));
    arr[(*size)-1]=element; 
    return arr;
}
int *insert_beg(int *arr,int *size,int element)
{
    (*size)++;
    arr=(int*)realloc(arr,(*size)*sizeof(int));
    for (int i = (*size)-2;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=element;
    return arr;
}
int *insert_pos(int *arr,int *size,int element,int pos)
{
    (*size)++;
    arr=(int*)realloc(arr,(*size)*sizeof(int));
    if (pos>(*size)||pos<1){

        printf ("Invalid !\n");
        (*size)--;
        return arr;
    }
    else
    {
        for (int i=(*size)-2;i>=pos-1;i--)
        {
            arr[i+1]=arr[i];
        }
    }
    arr[pos-1]=element;
    return arr;
}
int *insert_next(int *arr,int *size,int element ,int next){
    int pos=-1;
    for (int i=0;i<(*size);i++)
    {
        if (next==arr[i])
        {
            pos=i+1;
            break;
        }
    }
        if (pos==-1)
        {
            printf ("Invalid !\n");
            return arr;
        }
        (*size)++;
         arr=(int*)realloc(arr,(*size)*sizeof(int));
        for (int i=(*size)-2;i>=pos;i--)
        {
            arr[i+1]=arr[i];
        }
    arr[pos]=element;
    return arr;
    }
int main()
{
    int size,Input,element,pos,next;
    printf ("Enter the size of the array :\n");
    scanf ("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    for (int i=0;i<size;i++)
    {
        printf ("Enter element %d :",i);
        scanf ("%d",&arr[i]);
        
    }
    while (1)
    {
        printf ("Enter your choice :\n1)Traverse\n2)Insert at the end\n3)Insert at the beginning\n4)Insert at any position\n5)Insert after a given element\n6)Exit\n");
        scanf ("%d",&Input);
        switch (Input)
        {
            case 1:
            traverse (arr,size);
            break;
            case 2 :
            printf ("Enter the element to be inserted at the end :\n");
            scanf ("%d",&element);
            arr=insert_end (arr,&size,element);
            break;
            case 3 :
            printf ("Enter the element to be inserted at the beginning :\n");
            scanf ("%d",&element);
            arr=insert_beg (arr,&size,element);
            break;
            case 4 :
            printf ("Enter the element to be inserted at any position :\n");
            scanf ("%d",&element);
            printf ("Enter the position :\n");
            scanf ("%d",&pos);
            arr=insert_pos(arr,&size,element,pos);
            break;
            case 5 :
            printf ("Enter the element to be inserted at after a given element:\n");
            scanf ("%d",&element);
            printf ("Enter the given element:\n");
            scanf ("%d",&next);
            arr=insert_next(arr,&size,element,next);
            break;
            case 6:
            free (arr);
            exit (0);
            break;
            default :
            printf ("Invalid !");
            break;
        }

    }
   return 0;
}