#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
double dp[100009];
double w[1009];
int main()
{
    int n,v1;
    double v;
    //freopen("C:\\in.txt","r",stdin);
    while (~scanf("%d%lf",&n,&v))
    {
        v1=(int)((v+0.01)*10);
        double c;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
          {
              scanf("%lf%lf",&c,&w[i]);
              int c1=(int)((c+0.01)*10);
                for(int j=v1;j>=c1;j--)
                dp[j]=max(dp[j],dp[j-c1]+w[i]);
          }
        printf("%.1lf\n",dp[v1]);
    }
    return 0;
}
