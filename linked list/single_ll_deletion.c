#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * createNode(int data)
{
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
}
int del_beg(struct node** start)
{
    if ((*start)==NULL)
    {
        printf("Linked list is empty");
        return -999;
    }
    else
    {
        struct node* temp= *start;
        (*start)=(*start)->next;
        int val=temp->data;
        free(temp);
        return val;
    }
}
int del_end(struct node** start)
{
    if((*start==NULL))
    {
        printf("Linked list is empty");
        return -999;
    }
    else
    {
        struct node* temp=*start,*prev=NULL;
        for(;temp->next!=NULL;prev=temp,temp=temp->next);
        prev = NULL;
        int val = temp->data;
        free(temp);
        return val;
    }
}
int del_pos(struct node** start, int pos)
{
    if ((*start==NULL))
    {
        printf("Linked list is empty");
        return -999;
    }
    else
    {
        struct node*temp=(*start),*prev=NULL;
        for(int i=1;i<pos;i++)
        {
            if (temp->next==NULL)
            {
                printf("linked list is empty");
                return -999;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next=temp->next;
        int val = temp->data;
        free(temp);
        return val;
    }
}
int del_aft_ele(struct node** start, int ele)
{
    if((*start)==NULL)
    {
        printf("linked list is empty");
        return -999;
    }
    else
    {
        struct node* temp= (*start),*prev=NULL;
        if ((*start)->data==ele && (*start)->next!=NULL)
        {
            temp=(*start)->next;
            (*start)->next=temp->next;
            int val = temp->data;
            free(temp);
            return val;
        }
        
        for (;temp->data!=ele;prev=temp,temp=temp->next)
        {
            if (temp->next==NULL)
            {
                printf("ele not found");
                return -999;
            }
        }
        prev->next=temp->next;
        int val=temp->data;
        free(temp);
        return val;
    }
}
int main()
{
    return 0;
}