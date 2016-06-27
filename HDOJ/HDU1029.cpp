#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define FOR(x) for(int i=0;i<x;i++)
long long num[10000001];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        FOR(n)
            scanf("%d",&num[i]);
        sort(num,num+n);
        printf("%d\n",num[(n+1)/2-1]);
    }
    return 0;
}
