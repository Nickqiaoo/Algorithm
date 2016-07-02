#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1009];
int w[1009],c[1009];
int main()
{
    int t,n,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&v);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
            for(int i=0;i<n;i++)
                for(int j=v;j>=c[i];j--)
                dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        printf("%d",dp[v]);
    }
    return 0;
}
