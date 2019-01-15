#include<bits/stdc++.h>
using namespace std;

int mat[100][100];

int main()
{
    int c,n;
    cin>>c>>n;
    memset(mat,999999,sizeof mat);

    // for(int i=1;i<=n;i++)
    //   mat[i][i]=0;

    for(int i=0; i<n; i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        mat[a][b]=d;
        mat[b][a]=d;
    }

    for(int k=1; k<=c; k++)
    {


        for(int i=1; i<=c; i++)
        {
            for(int j=1; j<=c; j++)
            {
                mat[i][j]=min(mat[i][j],max(mat[i][k],mat[k][j]));
            }


        }
    }







    for(int i=1; i<=c; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}

/*
7 9
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140


7 6
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40


*/



///FOR finding the maximum
/*
#include<bits/stdc++.h>
using namespace std;

int mat[100][100];

int main()
{
    int c,n;
    cin>>c>>n;
    memset(mat,-1,sizeof mat);

     for(int i=1;i<=n;i++)
      mat[i][i]=0;

    for(int i=0; i<n; i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        mat[a][b]=d;
        mat[b][a]=d;
    }



    for(int k=1; k<=c; k++)
    {


        for(int i=1; i<=c; i++)
        {
            for(int j=1; j<=c; j++)
            {
                mat[i][j]=mat[j][i]=max(mat[i][j],min(mat[i][k],mat[k][j]));
            }


        }
    }







    for(int i=1; i<=c; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}
*/
