#include <stdio.h>
int main() 
{
    int arr[]={1,5,3,5,2,4,2,5,2,5};
    int n=10;
    for(int i=0;i<n-1;i++)
    {
        int min=arr[i];
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                pos=j;
            }
        }
        if(pos!=i)
        {
            arr[pos]=arr[i];
            arr[i]=min;
        }
    }
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
