# include<stdio.h>
typedef struct node
{
    int info;
    struct node *next;
}nodetype;
nodetype *push(nodetype *);
nodetype *pop(nodetype *);
void display(nodetype *);
void main()
{
    int c;
    char ch;
    nodetype *top=NULL;
    do
    {
        printf("enter u r choice1.push 2.pop 3.display");
        scanf("%d",&c);
        switch(c)
        {
            case 1:top=push(top);
            break;
            case 2:
                if(top==NULL)
                    printf("nothing to pop");
                else
                    top=pop(top);
                break;
            case 3: display(top);
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
nodetype *push(nodetype *top)
{
    nodetype *p;
    p=(nodetype*)malloc(sizeof(nodetype));
    scanf("%d",&(p->info));
    p->next=NULL;
    if(top==NULL)
        top=p;
    else
    {
        p->next=top;
        top=p;
    }
    return(top);
}
nodetype *pop(nodetype *top)
{
    nodetype *temp=top;
    printf("popped=%d",top->info);
    top=top->next;
    free(temp);
    return(top);
}
void display(nodetype *top)
{
    if(top==NULL)
        return;
    else
    {

        display(top->next);
        printf("%d",top->info);
    }
}
