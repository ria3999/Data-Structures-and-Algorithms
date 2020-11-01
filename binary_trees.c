#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}nodetype;



nodetype* newnode(int data)
{
      printf("h");
    nodetype *p=(nodetype *)malloc(sizeof(nodetype));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}
nodetype* buildtree()
{
    int d;
    printf("Enter data");
    scanf("%d",&d);
    if(d==-1)
        return NULL;
    nodetype *root=newnode(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void inorder(nodetype *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(nodetype *root)
{
    if(root==NULL)
        return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(nodetype *root)
{
    if(root==NULL)
        return;
    printf("%d",root->data);
    postorder(root->left);
    postorder(root->right);
}
int main()
{
    int c,n;
    nodetype *root=NULL;
    do
    {
        printf("Make a choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            root=buildtree();
             printf("h");
            break;
            case 2:
            inorder(root);
            break;
            case 3:
            preorder(root);
            break;
            case 4:
            postorder(root);
            break;
        }
        printf("So you want to continue?");
        scanf("%d",&n);
    }while(n!=0);
    return 0;
}
