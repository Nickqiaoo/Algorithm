#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int next1[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int ch[1005][1005];
struct nu
{
    int x,y,from,sum;

};
int num [1005][1005][4];

int bfs(int ax,int ay,int ex,int ey)
{
    if(ch[ax][ay]!=ch[ex][ey]||ch[ax][ay]==0||ch[ex][ey]==0)
        return 0;
    queue<nu>q;nu s;
    s.x=ax;s.y=ay;
    while(!q.empty())
        q.pop();
        q.push(s);

    while(!q.empty())
    {
        nu fx=q.front();
        if(fx.x==ex&&fx.y==ey)
            return 1;
        for(int i=0;i<=3;i++)
        {
            nu fy;
             fy.x=fx.x+next1[i][0];
             fy.y=fx.y+next1[i][1];
            if(fy.x>=0&&fy.x<n&&fy.y>=0&&fy.y<m&&(ch[fy.x][fy.y]==0||(fy.x==ex&&fy.y==ey))&&num[fy.x][fy.y][i]<2)
            {

                if(fx.x==ax&&fx.y==ay)
                    {
                       fy.from=i;
                        fy.sum=0;
                        q.push(fy);
                        num[fy.x][fy.y][i]++;
                    }
                else
                {
                    if(i==fx.from)
                    {
                        fy.from=i;
                        fy.sum=fx.sum;
                        q.push(fy);
                        num[fy.x][fy.y][i]++;
                    }

                    if(i!=fx.from&&fx.sum<2)
                    {
                       fy.from=i;
                        fy.sum=fx.sum+1;
                        q.push(fy);
                        num[fy.x][fy.y][i]++;
                    }
                }
            }
        }
        q.pop();
    }
    return 0;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
    {
        for (int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            scanf("%d",&ch[i][j]);
            int q1,x1,x2,y1,y2;
            scanf("%d",&q1);
            while(q1--)
            {
                memset(num,0,sizeof(num));
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
               if(bfs(x1-1,y1-1,x2-1,y2-1))
                printf("YES\n");
               else
                printf("NO\n");
            }
    }
    return 0;
}
