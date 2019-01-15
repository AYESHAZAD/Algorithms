#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int dist[110],u,v;
vector < pair<int,int> > node[100];

void bfs_value(int src)
{
    queue< pair<int,int> > q;
    dist[src]=0;
    q.push(make_pair(src,0));

    while(!q.empty())
    {
        u=q.front().first;
        q.pop();
        for(int i=0; i<node[u].size(); i++)
        {
            int v=node[u][i].first;
            int w=node[u][i].second;

            if(dist[v]==-1)
            {
                dist[v]=dist[u]+w;
                q.push(make_pair(v,w));
            }

        }
    }

}


int main()
{
    int n,e;
    printf("Enter the no. of node and edge:");
    while(cin>>n>>e)
    {


        printf("\n\nEnter the edges and corresponding cost:\n");
        for(int i=0; i<e; i++)
        {
            int a,b,cost;
            cin>>a>>b>>cost;

            node[a].push_back(make_pair(b,cost));
            node[b].push_back(make_pair(a,cost));
        }

        /*  for(int i=1;i<=n;i++)
          {
              for(int j=0;j<node[i].size();j++)
              {
                  cout<<node[i][j].first<<" "<<node[i][j].second<<" ";
              }
              cout<<endl;
          }*/

        memset(dist,-1,sizeof dist);
        int r;
        printf("\nEnter the starting node:\n");
        cin>>r;
        bfs_value(r);

        for(int i=1; i<=n; i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;

        for(int i=1; i<=n; i++)
        {
            node[i].clear();
        }
    }
    return 0;
}
/*
1 2 2
1 3 8
2 5 4
5 6 15
4 5 5
2 4 3
3 10 4

1
*/

