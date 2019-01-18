#include<bits/stdc++.h>
using namespace std;

int mat[100][100],next[100][100];

void findpath(int x,int y)
{
    while(x!=y)
    {
        printf("%d ",x);
        x=next[x][y];

    }
    printf("%d",x);
    printf("\n");
}





int main()
{
    int n,e,s,d;
  printf("Node and Edge: ");
  cin>>n>>e;
    memset(mat,9999,sizeof mat);

    for(int i=1; i<=n; i++)
        mat[i][i]=0;

    for(int i=0; i<e; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mat[a][b]=c;
        next[a][b]=b;

    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(mat[i][j]>(mat[i][k]+mat[k][j]))
                {
                    mat[i][j]=mat[i][k]+mat[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }

    printf("\nSource and destination to find path:\n");
    cin>>s>>d;
    findpath(s,d);


    return 0;
}

/*

4 5
1 2 7
1 3 1
3 4 9
3 2 2
2 4 1
*/

