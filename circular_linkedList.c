#include <stdio.h>
#include <stdlib.h>
typedef struct ll
{
    int data;
    struct ll *next;
}nodetype;


nodetype * insert(nodetype *fst,nodetype *lst )
{
    printf("Reached here");
    nodetype *temp=(nodetype *)malloc(sizeof(nodetype));
    if(temp==NULL)
    printf("Memory not allocated");
    else
    {
    printf("Enter data");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(fst==NULL && lst==NULL)
    {
        lst=temp;
    }
    else
    {
        lst->next=temp;
        lst=temp;
    }
    lst->next=fst;
    }
    return lst;
}
void display(nodetype *fst,nodetype *lst)
{
    if(fst==NULL)
    printf("\nNo element");
    else
    {
        do
    {
        printf("%d",fst->data);
        fst=fst->next;
    } while(fst!=lst->next);

    }
}
int main()
{
    nodetype *fst=NULL,*lst=NULL;
    int c;
    int ch=0;
    do
    {
    printf("Enter your choice");
    scanf("%d",&c);
    switch(c)
    {
        case 1: lst=insert(fst,lst);
        if(fst==NULL)
        fst=lst;
        break;
        case 2:display(fst,lst);
        break;
    }
    ch++;
    printf("\n");
    }while(ch!=4);
    return 0;
}
