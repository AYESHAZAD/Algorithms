#include<bits/stdc++.h>

using namespace std;
int mark[10000002],prime[3000000],nprime=0;
void sieve(int n)
{
    int i,j;
    int limit=sqrt(n*1)+2;
    mark[1]=1;
    for(i=4;i<=n;i+=2)
    {
        mark[i]=1;
    }
    prime[nprime++]=2;

    for(i=3;i<=n;i++)
    {
        if(!mark[i])
        {
            prime[nprime++]=i;
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j]=1;
                }
            }
        }
    }

    printf("\nThe primes in the range :\n ");

    for(i=0;i<nprime;i++)
    {
        printf("%d ",prime[i]);
    }



}


int main()
{
    sieve(20);
    return 0;
}
