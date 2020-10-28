# include<stdio.h>
typedef struct node
{
    int info;
    struct node *next;
}nodetype;
nodetype *insert(nodetype *);
nodetype *delet(nodetype *);
void display(nodetype *);
void main()
{
    int c;
    char ch;
    nodetype *front=NULL,*rear=NULL;
    do
    {
        printf("enter u r choice1.push 2.pop 3.display");
        scanf("%d",&c);
        switch(c)
        {
            case 1:rear=insert(rear);
            if(front==NULL)
                front=rear;
            break;
            case 2:
                if(front==NULL)
                    printf("nothing to pop");
                else
                    front=delet(front);
                break;
            case 3:
                if(front==NULL)
                    print("nothing to display");
                else
                    display(front);
                 break;
            default:
                printf("invalid choice");
                break;
        }
        printf("do you want to continue?");
        fflush(stdin);
        scanf("%c",&ch);
    }while(toupper(ch)=='Y');
}
nodetype *insert(nodetype *rear)
{
    nodetype *temp;
    if(temp==NULL)
        printf("Memory not allocated");
    else
    {
    temp=(nodetype *)malloc(sizeof(nodetype));
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(rear==NULL)
    {
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=rear->next;
    }
    }
    return(rear);
}
nodetype *delet(nodetype *front)
{
    nodetype *temp=front;
    printf("deleted element=%d",front->info);
    front=front->next;
    free(temp);
    return(front);
}
void display(nodetype *front)
{
    nodetype *t;
    t=front;
    while(t!=NULL)
    {
        printf("%d",t->info);
        t=t->next;
    }
}
