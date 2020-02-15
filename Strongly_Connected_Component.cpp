#include<bits/stdc++.h>
using namespace std;
/// complexity 2 O(V+E)
const int mx = 100005;
typedef  vector <int> ii;
ii g[mx];//graph
ii r[mx];//reverse graph
ii top; //as stack
ii p[mx];

int comp[mx],indegree[mx];
bool visited[mx];


void reset(int n)
{
    for(int i=0; i<=n; i++)
    {
        g[i].clear();
        r[i].clear();
        p[i].clear();
    }
    top.clear();

    memset(comp,0,sizeof comp);
    memset(indegree,0,sizeof indegree);
    memset(visited,false,sizeof visited);

}



void dfs1(int u)
{
    visited[u]=true;

    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];

        if(visited[v]==false)
            dfs1(v);
    }

    top.push_back(u);
}


void dfs2(int u,int c)
{
    visited[u]=true;
    comp[u]=c;

    for(int i=0; i<r[u].size(); i++)
    {
        int v=r[u][i];

        if(visited[v]==false)
            dfs2(v,c);
    }
}


int main()
{
    int n,e;
    while(cin>>n>>e)
    {

        reset(n);
        for(int i=0; i<e; i++)
        {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            r[b].push_back(a);
        }

        /// dfs on directed graph
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false)
                dfs1(i);
        }

        for(int i=0; i<=n; i++)
            visited[i]=0;



        ///dfs on reverse graph using top
        int cnt=0;
        for(int i=top.size()-1; i>=0; i--)
        {
            if(visited[top[i]]==false)
            {
                dfs2(top[i],++cnt);
            }

        }

        /// nodes in individual component
        for(int i=0; i<n; i++)
        {
            p[comp[i]].push_back(i);
        }

       /// indegree calculation
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<g[i].size(); j++)
            {
                if(comp[i]!=comp[g[i][j]])
                {
                    indegree[comp[g[i][j]]]++;
                }


            }
        }


       ///print all

        for(int i=1; i<=cnt; i++)
        {
            printf("{ ");
            for(int j=0; j<p[i].size(); j++)
            {
                printf("%d ",p[i][j]);
            }

            printf("}\n");

            printf("The indegree of the component is %d\n",indegree[i]);
        }





    }



    return 0;
}



/*
8 9
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
6 7

*/
