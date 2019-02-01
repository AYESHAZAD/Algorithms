#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vc;
vc v[1005];
int dist[100];

void dijkstra(int src)
{
    priority_queue <ii ,vector<ii> , greater<ii> > pq;

    dist[src]=0;
    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if(d>dist[u])
            continue;

        for(int i=0;i<v[u].size();i++)
        {
            ii x=v[u][i];
            if(dist[u]+x.second<dist[x.first])
            {
                dist[x.first]=dist[u]+x.second;
                pq.push(make_pair(dist[x.first],x.first));
            }
        }
    }

}


int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        v[a].push_back(make_pair(b,cost));

    }
  memset(dist,999999,sizeof dist);
    dijkstra(1);

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    for(int i=1;i<=n;i++)
        v[i].clear();

    return 0;
}

/*
Directed
1 2 1
1 4 9
2 3 2
3 5 1
5 2 6
3 4 1

*/
