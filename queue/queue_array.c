#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max];
int f = -1, r = -1;
int is_empty()
{
    if(f == -1 || f > r)
    return 1;
    return 0;
}
int is_full()
{
    if(r == max - 1)
    return 1;
    return 0;
}
void enqueue ( int data )
{
    if(is_full())
    {
        printf("overflow \n");
        return;
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
    queue[++r]=data;
    }
}
int dequeue()
{
    if(is_empty())
    {
        printf("underflow \n");
        return -999;
    }
    else
    {
        int val =  queue[f];
        if(f==r) f=r=-1;
        else f++;
        return;
    }
}
void traverse()
{
    if (is_empty())
    {
        printf("queue is empty \n");
        return;
    }
    for (int i = f; i != r; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    return 0;
}