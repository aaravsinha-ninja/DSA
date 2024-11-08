#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue1[max],queue2[max];
int f1=-1;
int r1=-1;
int f2=-1;
int r2=-1;
int top=-1;
int Is_Empty1()
{
    if (f1==-1)
    return 1;
    return 0;

}int Is_Full1()
{
    if (f1==(r1+1)%max)
    return 1;
    return 0;
}
int Is_Empty2()
{
    if (f2==-1)
    return 1;
    return 0;

}int Is_Full2()
{
    if (f2==(r2+1)%max)
    return 1;
    return 0;
}
void Enqueue1(int data)
{
    if (Is_Full1())
    {
        printf ("Queue 1 is Overflow");
        return;
    }
    if (f1==-1)
    f1=0;
    r1=(r1+1)%max;
    queue1[r1]=data;
}
void Enqueue2(int data)
{
     if (Is_Full2())
    {
        printf ("Queue 2 is Overflow");
        return;
    }
    if (f2==-1)
    f2=0;
    r2=(r2+1)%max;
    queue2[r2]=data;
}
int dequeue1() {
    if (Is_Empty1()) {
        printf("Queue 1 is underflow\n");
        return -999;
    }
    int value = queue1[f1];
    if (f1 == r1) {
        f1 = r1 = -1;  // Properly close the block for the if statement
    } else {
        f1 = (f1 + 1) % max;
    }
    return value;
}

int dequeue2() {
    if (Is_Empty2()) {
        printf("Queue 2 is underflow\n");
        return -999;
    }
    int value = queue2[f2];
    if (f2 == r2) {
        f2 = r2 = -1;  // Properly close the block for the if statement
    } else {
        f2 = (f2 + 1) % max;
    }
    return value;
}
void push (int data)
{
    if (Is_Full1())
    {
        printf ("Stack is overflow");
        return;
    }
    Enqueue2(data);
    while(!Is_Empty1())
    Enqueue2(dequeue1());
    while(!Is_Empty2())
    Enqueue1(dequeue2());
}
int pop()
{
    if (f1==-1)
    {
        printf("Stack is Underflow");
        return -999;
    }
    return dequeue1();
}
int main()
{
   return 0;
}