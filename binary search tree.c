#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int *left;
    int data;
    int *right;
}treetype;
void create(treetype **root,int num)
{
    treetype *p;
    if(*root==NULL)
    {
        p=(treetype *)malloc(sizeof(treetype));
        if(p!=NULL)
        {
            p->data=num;
            p->left=NULL;
            p->right=NULL;
            *root=p;
        }
        else
        printf("Not enough memory");
    }
    else if(num<(*root)->data)
    create(&(*root)->left,num);
    else
    create(&(*root)->right,num);
    return;
}
void inorder(treetype *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(treetype *root)
{
    if(root==NULL)
    return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(treetype *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
int search(treetype *root,int key)
{
    if(root==NULL)
        return 0;
    if(key==root->data)
        return 1;
    else if(key<root->data)
        return search(root->left,key);
    else
        return search(root->right,key);

}
treetype *findmin(treetype *root)
{
    treetype *p=root;
    while(p->left!=NULL)
    {
        p=p->left;
    }
    return(p);
}
treetype* deleting(treetype *root,int val)
{
    if(root==NULL)
        return root;
    if(val<root->data)
    root->left=deleting(root->left,val);
    else if(val>root->data)
    root->right=deleting(root->right,val);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            treetype *temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            treetype *temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else
        {
            treetype *temp=findmin(root->right);
            root->data=temp->data;
            root->right=deleting(root->right,temp->data);
        }
    }
    return root;

}
void inorder_predecessor(treetype *root,treetype **pre,treetype **suc, int key)
{
    if(root==NULL)
        return;
    if(root->data==key)
    {
        if(root->left!=NULL)
        {
            treetype *k=root->left;
            while(k->right)
            k=k->right;
           *pre=k;
        }
        if(root->right!=NULL)
        {
            treetype *k=root->right;
            while(k->left)
            k=k->left;
            *suc=k;
        }
        return;
    }
    if(root->data>key)
    {
        *suc=root;
        inorder_predecessor(root->left,&(*pre),&(*suc),key);
    }
    else
    {
        *pre=root;
        inorder_predecessor(root->right,&(*pre),&(*suc),key);
    }
    return;
}
int countnodes(treetype *root)
{
    if(root==NULL)
        return 0;
    return 1+countnodes(root->left)+countnodes(root->right);
}
void inorder_array(treetype *root,int arr[],int *indexptr)
{
    if(root==NULL)
        return;
    inorder_array(root->left,arr,indexptr);
    arr[*indexptr]=root->data;
    (*indexptr)++;
    inorder_array(root->right,arr,indexptr);
}
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void array_to_bst(treetype *root,int *arr,int *index_ptr)
{
    if(root==NULL)
        return;
    array_to_bst(arr,root->left,index_ptr);
    root->data=arr[*index_ptr];
    (*index_ptr)++;
    array_to_bst(arr,root->right,index_ptr);
}
void binary_to_bst(treetype *root)
{
    if(root==NULL)
        return;
    int c=countnodes(root);
    int arr[c];
    int i=0;
    inorder_array(root,arr,&i);
    qsort(arr, c, sizeof(arr[0]), compare);
    i=0;
    array_to_bst(root,arr,&i);
    return;
}
int main()
{
    treetype *root=NULL,*pre=NULL,*suc=NULL;
    int num,c,ch,key,l,val,k;
    do
    {
    printf("Choose an option:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        printf("Enter a value:");
        scanf("%d",&num);
        create(&root,num);
        break;
        case 2:
        printf("\n Inorder: ");
        inorder(root);
        printf("\n Preorder: ");
        preorder(root);
        printf("\n Postorder: ");
        postorder(root);
        break;
        case 3:
        printf("Enter the value of key:");
        scanf("%d",&key);
        l=search(root,key);
        if(l==1)
            printf("found");
        else
            printf("not found");
        break;
        case 4:
        printf("Enter the value of node you want to delete");
        scanf("%d",&val);
        root=deleting(root,val);
        inorder(root);
        break;
        case 5:
            printf("enter element of which predecessor and successor has to be found");
            scanf("%d",&k);
            inorder_predecessor(root,&pre,&suc,k);
            printf("Predecessor:%d\n",pre->data);
            printf("Successor:%d\n",suc->data);
            break;
        case 6:
            binary_to_bst(root);
            inorder(root);
            break;
    }
    printf("Do u want to continue?");
    scanf("%d",&ch);
    }while(ch!=0);
    return 0;
}
