#include<stdio.h>
#include<stdlib.h>
#define max 8
int queue[max] = {1, 2, 3, 4, 5, 6, 7, 8};
int f = 0, r = 7;
int isFull()
{
    if(f==(r+1)%max)
    return 1;
    return 0;
}
int isEmpty()
{
    if(f==-1)
    return 1;
    return 0;
}
void enqueue_right(int data)
{
    if (isFull())
    {
        printf("Queue overflow");
        return;
    }
    else
    {
        if (f==-1)  f=r=0;
        else    r=(r+1)%max;
        queue[r]=data;
    }
}
void enqueue_left(int data)
{
    if (isFull())
    {
        printf("Queue overflow");
        return;
    }
    else
    {
        if (f==-1)  f=r=0;
        else    f=(f-1+max)%max;
        queue[f]=data;
    }
}
int dequeue_left()
{
    if(isEmpty())
    {
        printf("Queue underflow");
        return -999;
    }
    else
    {
        int value = queue[f];
        if(f==r) f=r=-1;
        else f=(f+1)%max;
        return value;
    }
}
int dequeue_right()
{
    if(isEmpty())
    {
        printf("Queue underflow");
        return -999;
    }
    else
    {
        int value = queue[r];
        if(f==r) f=r=-1;
        else r=(r-1+max)%max;
        return value;
    }
}
void traversal()
{
    if (isEmpty())
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        for(int i = f;;i=(i+1)%max)
        {
            printf("%d",queue[i]);
            if(i==r)
            break;
        }
        printf("\n");
    }
}
int main()
{
    printf("start");
    traversal();
    printf("end");
    return 0;
}