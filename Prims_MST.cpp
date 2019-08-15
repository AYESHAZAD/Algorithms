#include<bits/stdc++.h>
using namespace std;
#define visited 1
#define unvisited -1
typedef pair <int,int> pi;
typedef vector<pi> vc;
vc node[100005];
int arr[100005];
priority_queue <pi> pq;

void prims(int src)
{
    arr[src]=1;

    for(int i=0;i<node[src].size();i++)
    {
        pi v=node[src][i];

        if(arr[v.first]==-1)
          pq.push(make_pair(-v.second,-v.first));
    }
}


int main()
{
    int n,m,x;
    while(cin>>n>>m)
    {
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            node[a].push_back(make_pair(b,c));
            node[b].push_back(make_pair(a,c));

        }

        memset(arr,-1,sizeof arr);
        cin>>x;
        prims(x);
        int cost=0;

        while(pq.size())
        {
            pi ff=pq.top();
            pq.pop();
            int x=-ff.first;
            int y=-ff.second;

            if(arr[y]==-1)
            {
                cost+=x;
                prims(y);
            }
        }

        printf("The MST weight =: %d\n",cost);

        for(int i=0;i<=n;i++)
          node[i].clear();
    }
    return 0;
}

/*
5 8
1 2 2
1 3 4
1 5 6
2 4 3
2 5 6
3 5 5
3 4 6
4 5 6
1

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
8 7 7
7 6 1
6 5 2
8 6 6
0

*/
