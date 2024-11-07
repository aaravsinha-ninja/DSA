#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int pri;
    struct node* next;
}queue;
queue* f = NULL;
queue* r = NULL;
queue* createNode(int data, int pri)
{
    queue* newNode = (queue*)malloc(sizeof(queue));
    newNode->data=data;
    newNode->next=NULL;
    newNode->pri=pri;
    return newNode;
}
int isEmpty()
{
    if(f==NULL)
    return 1;
    return 0;
}
void enqueue_pri(int data,int pri)
{
    queue* newNode=createNode(data,pri);
    if(isEmpty())
    {
        f=r=newNode;
        return;
    }
    queue* temp = f;
    queue* prev = NULL;
    for (; temp != NULL && temp->pri <= pri; prev = temp, temp = temp->next);
    if (prev == NULL)
    {
        newNode->next = f;
        f = newNode;
    }
    else
    {
        prev->next = newNode;
        newNode->next = temp;
        if (temp == NULL)
            r = newNode;
    }
}
int main()
{
    return 0;
}