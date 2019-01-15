#include<bits/stdc++.h>
using namespace std;
int arr[200][200];
int main()
{
    int n;
    cin>>n;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        cin>>arr[i][j];

        }

    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]=min(arr[i][j],(arr[i][k]+arr[k][j]));
            }
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
    }
return 0;
}

/*
0 10 999 999 999
10 0 2 999 1
999 2 0 30 4
999 999 30 0 999
999 1 4 999 0
*/
