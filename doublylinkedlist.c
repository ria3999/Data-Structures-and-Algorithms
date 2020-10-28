# include<stdio.h>
# include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
}nodetype;
nodetype *create(nodetype *root)
{
    nodetype *temp,*p=root;
    temp=(nodetype *)malloc(sizeof(nodetype));
    if(temp==NULL)
        printf("memory not allocated");
    else
    {
    printf("enter node info");
    scanf("%d",&temp->info);
    temp->prev=NULL;
    temp->next=NULL;
    if(root==NULL)
        root=temp;
    else
    {
    while(p->next!=NULL)
        p=p->next;
    p->next=temp;
    temp->prev=p;
    }
    }
return(root);
}
nodetype *delet(nodetype *root)
{
    nodetype *temp=root,*s;
    while(temp!=NULL)
    {
        if(temp->info%2!=0)
        {
            if(temp->next==NULL&&temp==root)

            {
                s=temp;
                temp=NULL;
                root=NULL;
                free(s);
            }
            else if(temp==root &&temp->next!=NULL)
            {
                s=temp;
                temp=temp->next;
                temp->prev=NULL;
                root=temp;
                s->next=NULL;
                free(s);
            }
            else if(temp->next==NULL &&temp!=root)
            {
                s=temp;

                s->prev->next=NULL;
                s->prev=NULL;
                free(s);
            }
            else
            {
                s=temp;
                temp=temp->next;
                s->prev->next=s->next;
                s->next->prev=s->prev;
                s->prev=NULL;
                s->next=NULL;
                free(s);
            }

        }

    }
    return(root);
}
void display(nodetype *root)
{
    while(root!=NULL)
    {
        printf("%d",root->info);
        root=root->next;
    }
}
void main()
{
    int c;
    char ch;
    nodetype *root=NULL;
    do
    {
        printf("enter choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:root=create(root);
            break;
            case 2:root=delet(root);
            break;
            case 3:display(root);
            break;
            default:
            printf("invalid choice");
            break;
        }
        printf("Do you want to continue?");
        fflush(stdin);
        scanf("%c",&ch);
    }while(toupper(ch)=='Y');
}

