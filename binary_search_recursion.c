#include <stdio.h>
int func(int arr[],int l,int r,int k)
{
    if(r>=l)
    {
    int mid=l+(r-l)/2;
    if(arr[mid]==k)
    return mid;
    else if(arr[mid]>k)
    return func(arr,l,mid-1,k);
    else
    return func(arr,mid+1,r,k);
    }
    return -1;
}
int main() 
{
    int arr[]={1,2,3,4,5,6};
    int n=6;
    int z;
    z=func(arr,0,n,2);
    if(z==-1)
    printf("Not found");
    else
    printf("Found");
    return 0;
}
