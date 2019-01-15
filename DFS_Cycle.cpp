#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int  visited[100],cycle=0;
vector<int> node[100];

void dfs_cycle(int u)
{   int v;
    visited[u]=1;

    for(int i=0;i<node[u].size();i++)
    {
         v=node[u][i];
         if(visited[v]==0)
        {
            dfs_cycle(v);
        }
        else if(visited[v]==1)
        {
            cycle=1;
            break;
        }


    }


    visited[u]=2;
}


int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
       // node[b].push_back(a);
    }
    memset(visited,0,sizeof visited);
     cycle=0;
    for(int i=1;i<=n && cycle==0;i++)
    {
        if(visited[i]==0)
        {
            dfs_cycle(i);
        }

    }

       if(cycle)
        {
             printf("Cycle Exits\n");
        }
        else
        {
             printf("Cycle does not exit\n");
        }



    for(int i=1;i<=n;i++)
    {
        cout<<visited[i]<<" ";
    }
    cout<<endl;
    return 0;
}


/*
5 5
1 2
2 3
3 4
4 2
2 5
*/
