#include<iostream>
#define inf 1<<30
using namespace std;

int arr[1006],n;


void merges(int p,int q,int r)
{
    int n1,n2,x=1,y=1;
    n1=q-p+1;
    n2=r-q;

    int L[n1+1],R[n2+1];///left and right subarray

    for(int i=1; i<=n1; i++)
        L[i]=arr[p+i-1];

    for(int j=1; j<=n2; j++)
        R[j]=arr[q+j];


    L[n1+1]=inf;
    R[n2+1]=inf;

    for(int k=p; k<=r; k++)
    {
        if(L[x]<=R[y])
        {
            arr[k]=L[x];
            x++;
        }
        else
        {
            arr[k]=R[y];
            y++;
        }
    }


}

void merge_sort(int p,int r)
{
    if(p<r)
    {
        int q=((p+r)/2);

        merge_sort(p,q);
        merge_sort(q+1,r);
        merges(p,q,r);
    }
}



int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>arr[i];

    merge_sort(1,n);

    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}

/*
6
3 4 5 1 2 8

*/
