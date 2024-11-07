#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack* next;
};
struct stack *top = NULL;
struct stack *createEle(int data)
{
    struct stack *newEle=(struct stack*)malloc(sizeof(struct stack));
    newEle->data=data;
    newEle->next=NULL;
    return newEle;
}
void push(int data)
{
    struct stack *newEle=createEle(data);
    newEle->next=top;
    top=newEle;
}
int pop()
{
    if (top==NULL)
    {
        printf("Stack underflow");
        return -999;
    }
    int x = top->data;
    struct stack *temp=top;
    top=top->next;
    free(temp);
    return x;
}
void traverse()
{
    if (top==NULL)
    {
        return;
    }
    int x = pop();
    traverse();
    printf("%d ",x);
    push(x);    
}
int main()
{
    return 0;
}