#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack [max];
int top = -1;
void push(int data)
{
    if (top==max-1)
    {
        printf("overflow");
        return;
    }
    stack[++top]=data;
}
int pop()
{
    if (top == -1)
    {
        printf("underflow");
        return -999;
    }
    int val = stack[top--];
    return val;
}
void traverse()
{
    if (top==-1)
    {
        return;
    }
    int x = pop();
    traverse();
    printf("%d",x);
    push(x);
}
void push_bottom(int data)
{
    if (top==-1)
    {
        push(data);
        return;
    }
    int x=pop();
    push_bottom(data);
    push(x);
}
void reverse()
{
    if (top==-1)
    {
        return;
    }
    int x=pop();
    reverse();
    push_bottom(x);
}
void push_sorted(int data)
{
    if (top==-1 || data > stack[top])
    {
        push(data);
        return;
    }
    int x = pop();
    push_sorted(data);
    push(x);    
}
void sort()
{
    if (top==-1)
    {
        return;
    }
    int x = pop();
    sort();
    push_sorted(x);
}
int main()
{
    int n,data,c;
    printf("\nenter the number of element to be pushed in the stack\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the element : %d\n",i);
        scanf("%d",&data);
        push(data);
    }
    while (1)
    {
        printf("\nchose from the operations to perform on the stack\npush element : 1\npop element : 2\npush element in the bottom of the stack : 3\nreverse elements : 4\ntraverse : 5\nexit : 0\n");
        scanf("%d",&c);
        switch (c)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\nEnter the element to push in the stack\n");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            printf("\npoped element is :- %d\n",pop());
            break;
        case 3:
            printf("\nEnter the element to be pushed in the bottom\n");
            scanf("%d",&data);
            push_bottom(data);
            break;
        case 4:
            reverse();
            printf("Elements are reversed!");
            break;
        case 5:
            traverse();
            break;
        default:
            printf("invalid input");
            break;
        }
    }
    return 0;
}