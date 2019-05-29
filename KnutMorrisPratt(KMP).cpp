///Pattern matching
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prefix[10005];

void set_prefix(string s)
{
    int i=0,j=-1,len;
    len=s.size();
    prefix[0]=-1;

    while(i<len)
    {
        while(j>=0 && s[i]!=s[j])
            j=prefix[j];

        i++;
        j++;
        prefix[i]=j;
    }

}

bool kmp_search(string s1,string s2)
{
    int i=0,j=0,n,m,cnt=0;
    n=s1.size();
    m=s2.size();
    set_prefix(s2);
    while(i<n)
    {
        while(j>=0 && s1[i]!=s2[j])
            j=prefix[j];

        i++;
        j++;
        if(j==m)
        {
            //cnt++;
            // j=0;

            return true;

        }
    }
    // return cnt;
    return false;
}


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    bool x=kmp_search(s1,s2);
    // int x=kmp_search(s1,s2);
    // cout<<x<<endl;

    if(x==true)
        printf("Pattern found\n");
    else
        printf("Not found\n");

    return 0;
}
/*
AAAAABAAABA AABA
*/
