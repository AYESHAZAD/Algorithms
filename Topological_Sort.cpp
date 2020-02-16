#include<bits/stdc++.h>
using namespace std;

typedef vector<int> ii;
ii node[1000];
ii vc;
int in[1000];

void top_bfs(int n)
{
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();
        vc.push_back(u);
        q.pop();

        for(int i=0; i<node[u].size(); i++)
        {
            int v=node[u][i];
            in[v]--;

            if(in[v]==0)
                q.push(v);
        }
    }
}


int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        memset(in,0,sizeof in);

        for(int i=0; i<e; i++)
        {
            int a,b;
            cin>>a>>b;
            node[a].push_back(b);
            in[b]++;
        }

        top_bfs(n);

        for(int i=0; i<vc.size()-1; i++)
            cout<<vc[i]<<" ";
        cout<<vc[vc.size()-1]<<endl;

        for(int i=0; i<=n; i++)
            node[i].clear();
        vc.clear();


    }

    return 0;
}

/*
5 7
1 2
1 3
1 4
2 4
2 5
4 3
4 5

4 5
1 2
1 3
2 3
4 2
4 3
*/
