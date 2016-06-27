#include <iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int next1[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef pair<int,int>P;
char map[205][205];
int num[205][205];
int bfs(int sx,int sy,int ex,int ey)
{
    queue<P>q;
    while(!q.empty())
        q.pop();
    q.push(P(sx,sy));
    num[sx][sy]=1;
    while(!q.empty())
    {
        P step=q.front();
        if(step.first==ex&&step.second==ey)
            return num[ex][ey];
        for(int i=0;i<4;i++)
        {
            int nx=step.first+next1[i][0];
            int ny=step.second+next1[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&map[nx][ny]!='#'&&!num[nx][ny])
            {
                if(map[nx][ny]=='.'||map[nx][ny]=='a')
                {
                    q.push(P(nx,ny));
                    num[nx][ny]=num[step.first][step.second]+1;
                }
                if(map[nx][ny]=='x')
                {
                    q.push(P(nx,ny));
                    num[nx][ny]=num[step.first][step.second]+2;
                }
            }
        }
        q.pop();
    }
return 0;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(num,0,sizeof(num));
        int x1,y1,x2,y2;
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            if(map[i][j]=='r')
            {
                x1=i;y1=j;
            }
            if(map[i][j]=='a')
            {
                x2=i;y2=j;
            }
            }
            int flag=bfs(x1,y1,x2,y2);
            if(flag)
            printf("%d\n",flag-1);
            else
            printf("Poor ANGEL has to stay in the prison all his life.\n");

    }
    return 0;
}
