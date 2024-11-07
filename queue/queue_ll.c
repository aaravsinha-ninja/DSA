#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue* next;
};
struct queue *f=NULL;
struct queue *r=NULL;
struct queue *create_ele(int data)
{
    struct queue *new_ele=(struct queue*)malloc(sizeof(struct queue));
    new_ele->data=data;
    new_ele->next=NULL;
    return new_ele;
}
int is_empty()
{
    if(f==NULL)
    return 1;
    return 0;
}
void enqueue(int data)
{
    struct queue *temp=create_ele(data);
    if (is_empty())
    {
        f=r=temp;
        return;
    }
    r->next=temp;
    r=temp;    
}
int dequeue()
{
    if (is_empty())
    {
        printf("underflow \n");
        return -999;
    }
    struct queue *temp = f;
    int x = f->data;
    f=f->next;
    if (f == NULL) 
    {
        r = NULL;
    }
    free(temp);
    return x;
}
void traverse()
{
    if (is_empty())
    {
        return;
    }
    int x = dequeue();
    printf("%d ", x );
    traverse();
    enqueue(x);
}
int main()
{
    return 0;
}