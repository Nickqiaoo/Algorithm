#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int book[120][120],sum
int next1[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char num[120][120];
int n,m;
void dfs(int x,int y)
{
    int tx,ty;
    num[x][y]='*';
    for(int k=0;k<8;k++)
    {
        tx=x+next1[k][0];
        ty=y+next1[k][1];
        if(tx<0||tx>=n||ty<0||ty>=m)
            continue;
        if(num[tx][ty]=='@'&&book[tx][ty]==0)
        {
            book[tx][ty]=1;
            dfs(tx,ty);
        }
    }
    return ;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        sum=0;
        memset(book,0,sizeof(book));
        for(int i=0;i<n;i++)
            scanf("%s",num[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(num[i][j]=='@')
                {
                    sum++;
                    book[i][j]=1;
                    dfs(i,j);
                }
       printf("%d\n",sum);
    }
    return 0;
}
