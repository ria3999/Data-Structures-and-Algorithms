#include <iostream>
#include <math.h>
using namespace std;
bool jump_search(int arr[],int key,int n)
{
    int low=0;
    int c=1;
    cout<<low<<" ";
    int high=sqrt(n);
    cout<<high<<endl;
    while(arr[high]<key&& high<n-1)
    {
        c++;
        low=high;
        cout<<low<<" ";
        high+=sqrt(n);
        if(high>=n)
        high=n-1;
       cout<<high<<endl;

    }
    cout<<"final low="<<low<<"final high"<<high<<endl;
    for(int i=high;i>=low;i--)
    {
        cout<<arr[i];

        if(arr[i]==key)
        {
            c++;
            cout<<"comparisons="<<c;
        return true;
        }
     
    }
    cout<<"comparisons"<<c;
    return false;
}
int main() 
{
    int arr[]={21,39,40,45,51,54,68,72};
    int key=69;
    cout<<"key"<<key<<endl;
    int n=8;
    if(jump_search(arr,key,n))
    cout<<"\nFound";
    else
    cout<<"\nNot Found";
    return 0;
}
