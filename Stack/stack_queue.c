#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue1[max],queue2[max];
int f1=-1,r1=-1,f2=-1,r2=-1;
int is_full1()
{
    if(f1==(r1+1)%max)
    return 1;
    return 0;
}
int is_full2()
{
    if(f2==(r2+1)%max)
    return 1;
    return 0;
}
int is_empty1()
{
    if(f1==-1)
    return 1;
    return 0;
}
int is_empty2()
{
    if(f2==-1)
    return 1;
    return 0;
}
void enqueue1(int data)
{
    if (is_full1()) 
    {
        printf("Queue1 overflow\n");
        return;
    }
    r1=(r1+1)%max;
    if(f1==-1)
    f1=0;
    queue1[r1]=data;
}
void enqueue2(int data)
{
    if (is_full2()) 
    {
        printf("Queue2 overflow\n");
        return;
    }
    r2=(r2+1)%max;
    if(f2==-1)
    f2=0;
    queue2[r2]=data;
}
int dequeue1()
{
    if (is_empty1()) 
    {
        printf("Queue1 underflow\n");
        return -999;
    }
    int value = queue1[f1];
    if(f1==r1)
    f1=r1=-1;
    else
    f1=(f1+1)%max;
    return value;
}
int dequeue2()
{
    if (is_empty2()) 
    {
        printf("Queue2 underflow\n");
        return -999;
    }
    int value = queue2[f2];
    if(f2==r2)
    f2=r2=-1;
    else
    f2=(f2+1)%max;
    return value;
}
void push(int data)
{
    if (is_full1())
    {
        printf("stack overflow");
        return;
    }
    else
    {
        enqueue2(data);
        while(!is_empty1())
        enqueue2(dequeue1());
        while(!is_empty2())
        enqueue1(dequeue2());
    }
}
int pop()
{
    if (is_empty1())
    {
        printf("stack underflow");
        return -999;
    }
    else
    return dequeue1();
}
int main()
{
    return 0;
}