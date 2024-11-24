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
int count(tree* LOC)
{
    if(LOC==NULL)
        return 0;
    return 1 + count(LOC->LC) + count(LOC->RC);
}
struct node* in_order_pre(struct node* root)
{
    root=root->LC;
    for(;root->RC!=NULL;root=root->RC);
    return root;
}
struct node* deleteNode(struct node* root,int value)
{
    struct node* ipre = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->LC==NULL && root->RC==NULL)
    {
        free(root);
        return NULL;
    }
    if (value > root->data)
    {
        root->RC=deleteNode(root->RC,value);
    }
    else if (value < root->data)
    {
        root->LC =deleteNode(root->LC,value);
    }
    else
    {
        if (root->LC == NULL) {
            struct node* temp = root->RC;
            free(root);
            return temp;
        }
        if (root->RC == NULL) {
            struct node* temp = root->LC;
            free(root);
            return temp;
        }
        ipre=in_order_pre(root);
        root->data=ipre->data;
        root->LC=deleteNode(root->LC,ipre->data);
    }
    return(root);
}
int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(9);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \    \
    //  1   4   9
 
    // Linking the root node with left and right children
    p->LC = p1;
    p->RC = p2;
    p1->LC = p3;
    p1->RC = p4;
    p2->RC = p5;
    inorder(p);
    printf("\n");
    deleteNode(p, 6);
    inorder(p);

    return 0;
}