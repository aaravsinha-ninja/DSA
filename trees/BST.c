#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* LC;
    struct node* RC;
}tree;
tree* root = NULL;
tree* createNode(int data)
{
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->data=data;
    newNode->LC=NULL;
    newNode->RC=NULL;
    return newNode;
}
void insert(int data)
{
    tree* newNode = createNode(data);
    if(root==NULL)
    {
        root=newNode;
        return;
    }
    else
    {
        tree* loc = root;
        label:
        if (data<loc->data)
        {
            if(loc->LC==NULL)
            {
                loc->LC=newNode;
                return;
            }
            else
            {
                loc=loc->LC;
                goto label;
            }
        }
        else if(data>loc->data)
        {
            if(loc->RC==NULL)
            {
                loc->RC=newNode;
                return;
            }
            else
            {
                loc=loc->RC;
                goto label;
            }
        }
        else
        {
            printf("element already exists in the tree");
            return;
        }
    }
}
void preorder(tree*loc)
{
    if(loc!=NULL)
    {
        printf("%d",loc->data);
        preorder(loc->LC);
        preorder(loc->RC);
    }
}
void inorder(tree*loc)
{
    if(loc!=NULL)
    {
        inorder(loc->LC);
        printf("%d",loc->data);
        inorder(loc->RC);
    }
}
void postorder(tree*loc)
{
    if(loc!=NULL)
    {
        postorder(loc->LC);
        postorder(loc->RC);
        printf("%d",loc->data);
    }
}
int largest()
{
    if (root==NULL)
    {
        printf("tree is empty");
        return -999;
    }
    tree* loc = root;
    for(;loc->RC!=NULL;loc=loc->RC);
    return loc->data;
}
int smallest()
{
    if (root==NULL)
    {
        printf("tree is empty");
        return -999;
    }
    tree* loc = root;
    for(;loc->LC!=NULL;loc=loc->LC);
    return loc->data;
}
int count_leaf(tree*loc)
{
    if (loc==NULL)
    {
        printf("tree is empty");
        return 0;
    }
    else
    {
        if(loc->LC==NULL && loc->RC==NULL)
        return 1;
        return (count_leaf(loc->LC)+count_leaf(loc->RC));
    }
}
int main()
{
    preorder(root);
    return 0;
}