#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int next1[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int book[10][10],sum;
int a,b;
int dfs(int x,int y)
{
   int tx,ty;
   for(int k=0;k<8;k++)
    {
        tx=x+next1[k][0];
        ty=y+next1[k][1];
        if(tx==a&&ty==b)
            sum++;
        if(tx<1||tx>4||ty<1||ty>5)
            continue;
        if(book[tx][ty]==0)
        {
            book[tx][ty]=1;
            dfs(tx,ty);
            book[tx][ty]=0;
        }
    }
return sum;
}
int main()
{
    while(~scanf("%d%d",&a,&b))
    {
        sum=0;
        memset(book,0,sizeof(book));
        book[a][b]=1;
        printf("%d\n",dfs(a,b));
    }
    return 0;
}
