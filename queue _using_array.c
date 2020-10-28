# include<stdio.h>
# define max 5
int insertq(int[], int,int); // FUNCTION DECLARATION
int deleteq(int[],int,int);      // FUNCTION DECLARATION
void display(int[],int,int);
void main()
{
    int c,q[max],f=-1,r=-1;
    char ch;
    do
    {
    printf("enter choice\n1.insert\n2.delete\n3.display");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        if(f==0&&r==max-1||r+1==f)
            printf("queue is full");
        else
        {
          r=insert(q,f,r);
          if(r==0)
            f++;
        }
        break;
    case 2:
        if (f==-1)
            printf("queue is empty");
        else
            f=delet(q,f,r);
        break;
    case 3:
        if(f==-1)
            printf("nothing to display");
        else
            print(q,f,r);
        break;
    default:
        printf("invalid choice!");
        break;
    }
    printf("Do you want to continue?");
    fflush(stdin);
    scanf("%c",&ch);
    }while(toupper(ch)=='Y');
}
int insert(int q[],int f,int r)
{
    if(r==-1)
        r++;
    else if(f>0 && r==max-1)
        r=0;
    else
        r++;
    printf("enter element to be inserted");

    scanf("%d",&q[r]);
    return(r);
}
int delet(int q[],int f,int r)
{
    printf("Deleted element is %d",q[f]);
    if(f==r)
    {
        f=-1;
        r=-1;
    }
    else
    {
        f++;
    }
    return(f);
}
void print(int q[],int f,int r)
{
    int i;
    if(f>r)
    {
        for(i=f;i<=max-1;i++)
            printf("%d",q[i]);
        for(i=0;i<=r;i++)
            printf("%d",q[i]);
    }
    else
    {
        for(i=f;i<=r;i++)
            printf("%d",q[i]);
    }

}

