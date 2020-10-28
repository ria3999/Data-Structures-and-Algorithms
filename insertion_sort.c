#include <stdio.h>
int main()
{
    int arr[]={1,4,5,3,5,6,3,7,3};
    int n=9;
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
