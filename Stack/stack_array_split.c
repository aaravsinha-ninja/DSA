#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack [max];
int top_A = -1;
int top_B = max;
void push_A(int data)
{
    if (top_A==top_B-1)
    {
        printf("overflow");
        return;
    }
    top_A++;
    stack[top_A]=data;
}
void push_B(int data)
{
    if (top_A==top_B-1)
    {
        printf("overflow");
        return;
    }
    top_B--;
    stack[top_B]=data;
}
int pop_A()
{
    if (top_A==-1)
    {
        printf("underflow");
        return -999;
    }
    int x=stack[top_A--];
    return x;
}
int pop_B()
{
    if (top_B==max)
    {
        printf("underflow");
        return -999;
    }
    int x=stack[top_B++];
    return x;
}
void travers_A()
{
    if (top_A==-1)
    {
        return;
    }
    int x = pop_A();
    travers_A();
    printf("%d ",x);
    push_A(x);
}
void travers_B()
{
    if (top_B==max)
    {
        return;
    }
    int x = pop_B();
    travers_B();
    printf("%d ",x);
    push_B(x);
}
void push_bottom_A(int data)
{
    if (top_A==-1)
    {
        push_A(data);
        return;
    }
    int x = pop_A();
    push_bottom_A(data);
    push_A(x);
}
void push_bottom_B(int data)
{
    if (top_B==max)
    {
        push_B(data);
        return;
    }
    int x = pop_B();
    push_bottom_B(data);
    push_B(x);
}
void reverse_A()
{
    if (top_A==-1)
    {
        return;
    }
    int x = pop_A();
    reverse_A();
    push_bottom_A(x);
}
void reverse_B()
{
    if (top_B==max)
    {
        return;
    }
    int x = pop_B();
    reverse_B();
    push_bottom_B(x);
}
int main()
{
    return 0;
}