#include<bits/stdc++.h>
using namespace std;
vector<int> node[200];
int visited[200],disc[200],finish[200],cnt=1;

void dfs(int u)
{
    visited[u]=1;

    disc[u]=cnt++;

    for(int i=0; i<node[u].size(); i++)
    {
        int v=node[u][i];
        if(visited[v]==0)
        {
            visited[v]=1;
            dfs(v);
        }
    }
    finish[u]=cnt++;

}


int main()
{
    int n,e,s;
    while (cin>>n>>e)
    {


        for(int i=0; i<e; i++)
        {
            int a,b;
            cin>>a>>b;
            node[a].push_back(b);
            node[b].push_back(a);
        }

        memset(visited,0,sizeof visited);
        memset(disc,0,sizeof disc);
        memset(finish,0,sizeof finish);
        cnt=1;
        cin>>s;
        dfs(s);
        printf("Discovering Time of the nodes:\n\n");
        for(int i=1; i<=n; i++)
        {
            cout<<i<<"-->"<<disc[i]<<endl;
        }
        cout<<endl;

        printf("Finishing Time of the nodes:\n\n");
        for(int i=1; i<=n; i++)
        {
            cout<<i<<"-->"<<finish[i]<<endl;
        }
    }
    //count<<endl;
    return 0;
}

/*
7 9
1 2
1 4
2 3
2 4
3 7
3 5
5 6
7 6
7 4
1

*/
