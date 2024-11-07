#include<stdio.h>
#include<stdlib.h>
struct BST{
    int data;
    struct BST*lchild;
    struct BST*rchild;
};
struct BST*createtree(int data)
{
    struct BST*newtree=(struct BST*)malloc(sizeof(struct BST));
    newtree->data=data;
    newtree->lchild=NULL;
    newtree->rchild=NULL;
    return newtree;
}
struct BST*root=NULL;
void insert(int data){
    struct BST*newNode=createtree(data);
    if (root==NULL)
    {
        root=newNode;
        return;
    }
    else{
        struct BST*loc=root;
        label:
        if (data<loc->data){
            if (loc->lchild==NULL)
            {
                loc->lchild=newNode;
                return;
            }
            loc=loc->lchild;
            goto label;
        }
        else if (data>loc->data)
        {
            if (loc->rchild==NULL)
            {
                loc->rchild=newNode;
                return;
            }
            loc=loc->rchild;
            goto label;
        }
        else
        return;
    }
    struct queue*loc=root;
}
void preorder_traversal(struct BST*ptr)
{
    if (ptr!=NULL)
    {
        printf("%d",ptr->data);
        preorder_traversal(ptr->lchild);
        preorder_traversal(ptr->rchild);
    }
}
void inorder_traversal(struct BST*ptr)
{
    if (ptr!=NULL)
    {
        inorder_traversal(ptr->lchild);
        printf("%d",ptr->data);
        inorder_traversal(ptr->rchild);
    }
}
void postorder_traversal(struct BST*ptr)
{
    if (ptr!=NULL)
    {
        postorder_traversal(ptr->lchild);
        postorder_traversal(ptr->rchild);
        printf("%d",ptr->data);
    }
}
int main()
{
int size,data,input;
   printf ("Enter the number of elements to be inserted :\n");
   scanf ("%d",&size);
   for (int i=0;i<size;i++)
   {
    printf ("Element %d:",i);
    scanf ("%d",&data);
   } 
   while (1)
   {
    printf ("Enter your choice:\n1.Pre-Order Traversal\n2.In-Order Traversal\n3.Post-Order Traversal\n4.Exit\n");
    scanf ("%d",&input);
    switch(input)
    {
        case 1:
        printf ("Pre-Order Traversal :");
        preorder_traversal(root);
        break;
        case 2:
        printf ("In-Order Traversal :");
        inorder_traversal(root);
        break;
        case 3:
        printf ("Post-Order Traversal :");
        postorder_traversal(root);
        break;
        case 4:
        exit(0);
        break;
        default :
        printf ("Invalid Input !");
        break;

    }
   return 0;
   }
}