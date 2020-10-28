# include<stdio.h>
# include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}nodetype;
nodetype *create(nodetype *);
void display(nodetype *);
void main()
{
    nodetype *root=NULL;
    int c;
    char ch;
    do
    {
        printf("enter choice\n1.create\n2.display");
        scanf("%d",&c);
        switch(c)
        {
            case 1: root=create(root);
            break;
            case 2: display(root);
            break;
            default: printf("Invalid choice");
            break;
        }
        printf("Do you want to continue?");
        fflush(stdin);
        scanf("%c",&ch);
    }while(toupper(ch)=='Y');
}

nodetype* create(nodetype *root)
{
    nodetype *p=root;
    nodetype *temp;
    temp=(nodetype *)malloc(sizeof(nodetype));
    printf("enter node data");
    scanf("%d",&temp->data);
    if(root==NULL)
    {
        root=temp;
        temp->prev=NULL;
        temp->next=NULL;
    }
    else
    {
        while(p->next->data<temp->data)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
        p->next=temp;
         temp->prev=p;
         temp->next=NULL;
        }
        else
        {
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
        temp->prev=p;
    }
   return(root);
}
}
void display(nodetype *root)
{
    while(root!=NULL)
    {
        printf("%d",root->data);
        root=root->next;
    }
}


