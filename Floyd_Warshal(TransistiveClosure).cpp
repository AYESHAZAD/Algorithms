#include<bits/stdc++.h>
using namespace std;

int mat[100][100];

int main()
{
    int n,e;
    cin>>n>>e;

    memset(mat,0,sizeof mat);


    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {

                mat[i][j]=(mat[i][j]||(mat[i][k]&&mat[k][j]));

            }
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<mat[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;

}


/*

1 2
1 3
3 4
3 2
2 4

*/
