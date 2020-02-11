#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[50][50];
int lcs(int m,int n)
{
    for(int i=0;i<=m;i++)
        dp[i][0]=0;

    for(int j=0;j<=n;j++)
        dp[0][j]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }

            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }


    return dp[m][n];
}



int main()
{
    while(getline(cin,s1))
    {
        getline(cin,s2);

        int z,m=s1.size(),n=s2.size();
        memset(dp,0,sizeof dp);
        z=lcs(m,n);


        cout<<"Length of the longest subsequence is "<<z<<endl;
        /*for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
    }


    return 0;
}


/*
ACADB
CBDA
*/
