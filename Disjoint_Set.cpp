#include<bits/stdc++.h>
using namespace std;

int parent[1005],rk[1005];

void built(int n)
{
    for(int i=1;i<=n;i++)
        {
        parent[i]=i;
        rk[i]=0;
        }
}


int make_friend(int n)
{
    if(parent[n]==n)
        return n;
    else
        return parent[n]=make_friend(parent[n]);
}

void make_union(int a,int b)
{
    if(rk[a]>rk[b])
        parent[b]=a;

    else
        {
            parent[a]=b;

            if(rk[a]==rk[b])
                rk[b]++;
        }
}


int main()
{
    int n,e,x,y;
    cin>>n>>e;
    built(n);

    while(e--)
    {
        cin>>x>>y;

        int a=make_friend(x);
        int b=make_friend(y);
        if(a!=b)
            make_union(a,b);

        else
            printf("%d and %d are friends\n",x,y);
    }
    for(int i=1;i<=n;i++)
        cout<<parent[i]<<" ";


    return 0;
}
