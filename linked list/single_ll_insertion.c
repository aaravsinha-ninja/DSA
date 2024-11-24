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
    return newNode;
}
void insert_beginning(struct node**start,int data)
{   
    struct node * newNode = createNode(data);
    newNode->next=(*start);
    (*start)=newNode;
}
void insert_end(struct node** start, int data)
{
    struct node* newNode = createNode(data);
    if ((*start)==NULL)
    {
        (*start)=newNode;
        return;
    }
    struct node * temp = (*start);
    for(;temp->next!=NULL;temp=temp->next);
    temp->next=newNode;
}
void insert_pos(struct node** start, int data, int pos)
{
    struct node* newNode = createNode(data);
    if ((*start)==NULL && pos==1)
    {
        (*start)=newNode;
        return;
    }
    else if (pos<1 || (*start == NULL && pos > 1))
    {
        printf("invalid pos");
        return;
    }
    struct node* temp = *start;
    for(int i = 1; i < pos-1 ; i++)
    {
        if (temp->next==NULL)
        {
            printf("Invalid pos");
            return;
        }
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void insert_aft_ele(struct node** start, int data,int ele)
{
    struct node* newNode = createNode(data);
    if((*start)==NULL)
    {
        printf("Linked list is empty and element not found");
        return;
    }
    else
    {
        struct node* temp =(*start);
        for (;temp->data!=ele;temp=temp->next)
        {
            if (temp->next==NULL)
            {
                printf("ele not found");
                return;
            }
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
int main()
{
    int n,data;
    struct node* ll=NULL;
    printf("Enter the number of elements in the newNode");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of the data in node %d",i+1);
        scanf("%d",&data);
        insert_end(&ll,data);
    }
    return 0;
}