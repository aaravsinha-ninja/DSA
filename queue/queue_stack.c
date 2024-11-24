#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack1[max],stack2[max];
int top1=-1;
int top2=-1;
int Is_Empty1()
{
    if (top1==-1)
    return 1;
    return 0;
}
int Is_Full1()
{
    if (top1==max-1)
    return 1;
    return 0;
}
int Is_Empty2()
{
    if (top2==-1)
    return 1;
    return 0;
}
int Is_Full2()
{
    if (top2==max-1)
    return 1;
    return 0;
}
void push1(int data)
{
    if (Is_Full1())
    {
        printf ("Stack1 is Overflow");
        return;
    }
    stack1[++top1]=data;
}
void push2(int data)
{
    if (Is_Full2())
    {
        printf ("Stack2 is Overflow");
        return;
    }
    stack2[++top2]=data;
}
int pop1()
{
    if(Is_Empty1())
    {
        printf ("Stack 1 is underflow");
        return;
    }
    return stack1[top1--];
}
int pop2()
{
    if(Is_Empty2())
    {
        printf ("Stack 2 is underflow");
        return;
    }
    return stack2[top2--];
}
void enqueue(int data)
{
    if (Is_Full1())
    {
        printf ("Queue is Overflow");
        return;
    }
    push1(data);
}
int dequeue()
{
    if (Is_Empty1())
    {
        printf ("Queue is Underflow");
        return;
    }
    while(!Is_Empty1()){
    push2(pop1());
    }
    int popped_element=pop2();
    while(!Is_Empty2()){
    push1(pop2());
    }
    return popped_element;
}
int main()
{
   return 0;
}
