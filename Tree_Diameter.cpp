#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int dist[100],u,v;
vector<int> node[100];
void tree_bfs(int src)
{
    queue<int> q;
    dist[src]=0;
    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<node[u].size(); i++)
        {
            int v=node[u][i];

            if(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }

}


int main()
{
    int n,e,mx1=0,mx2=0,x,p;
    cin>>n>>e;
    printf("Enter the edges:\n");
    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    memset(dist,-1,sizeof dist);


    printf("\nEnter the source node: ");
    cin>>x;

    tree_bfs(x);

    for(int i=1; i<=n; i++)
    {
        if(mx1<dist[i])
        {
            mx1=dist[i];
            p=i;
        }
    }

//cout<<endl;
//cout<<p<<endl;

    /* for(int i=1; i<=n; i++)
     {
         cout<<dist[i]<<" ";
     }*/
    cout<<endl;

    memset(dist,-1,sizeof dist);
    tree_bfs(p);

    cout<<"Diameter of the tree is "<<dist[n]<<endl;;
    return 0;

}
/*
8 6
1 2
1 3
2 5
2 6
3 7
3 8
1
*/
