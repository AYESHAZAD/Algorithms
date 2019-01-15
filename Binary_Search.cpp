#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>

using namespace std;
int n,arr[10],y,t;

int b_search(int arr[],int t,int n)
{
    int low=0,high=n,mid;

    while(low<=high)
    {
        mid=(low+high)>>1;//it means divided by 2
        if(arr[mid]==t)
        {
            return mid;
        }

        else if(arr[mid]>t)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }

    }

    return -1;
}

int main()
{
    int result;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>y;
    sort(arr,arr+n);

    ///Built in function

    /* bool x=binary_search(arr,arr+n,y);

     if(x==true)
     {
         printf("Element found\n");

     }
     else
     {
         printf("Element not found\n");
     }
    */

    result=b_search(arr,y,n);

    if(result<0)
    {
        printf("Not Found\n");

    }

    else
    {
        printf("Found in index %d = %d\n",result,arr[result]);
    }


    return 0;
}
