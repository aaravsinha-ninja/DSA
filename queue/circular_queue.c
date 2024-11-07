#include<stdio.h>
#include<stdlib.h>
#define max 6
int queue[max];
int f=-1;
int r=-1;
int IsEmpty()
{
    if (f==-1)
    return 1;
    return 0;
} 
int IsFull()
{
    if (f==((r+1)%max))
    return 1;
    return 0;
}
void enqueue(int data)
{
    if (IsFull())
    {
        printf ("Overflow");
        return;
    }
    else{
        if (f==-1)
        {
            f=0;
        }
        r=(r+1)%max;
        queue[r]=data;
    }
}
int dequeue()
{
    int value;
    if (f==-1)
    {
        printf ("Underflow");
        return -999;
    }
    else{
        value = queue[f];
        if(f==r)
        {
            f=r=-1;
        }
        else
        f=(f+1)%max;
        return value;
    }
}

void traversal()
{
    if (f==-1)
    {
        printf ("Underflow");
        return;
    }
    for (int i=f;;i=(i+1)%max)
    {
        printf ("%d",queue[i]);
        if(i==r)
        {
            break;
        }
    }
    printf ("\n");
    
}
int main()
{
    int n,data;
    n=5;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&data);
        enqueue(data);
    }
    traversal();
    return 0;
}