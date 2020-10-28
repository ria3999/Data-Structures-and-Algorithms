#include <stdio.h>
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int left=0;
    int right=8;
    int mid,key=4;
    int f=0;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(arr[mid]==key)
        {
            f=1;
            break;
        }
        else if(key<arr[mid])
        {
            right=mid-1;
        }
        else
        left=mid+1;
    }
    if(f==0)
    printf("Not found");
    else
    printf("Found");
    return 0;
}
