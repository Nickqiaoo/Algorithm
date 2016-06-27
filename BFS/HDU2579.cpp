#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char map[102][102];
int num[102][102][10];
int next1[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int r,c,k;
struct step
{
    int x,y,sum;
}step1,step2,step3;
int bfs(int sx,int sy,int ex,int ey)
{
    queue<step>q;
    while(!q.empty())
        q.pop();
        step1.x=sx;step1.y=sy;step1.sum=0;
        q.push(step1);
    while(!q.empty())
    {
       step step2=q.front();
        if(step2.x==ex&&step2.y==ey)
            return step2.sum;
        for(int i=0;i<4;i++)
        {
            step3.x=step2.x+next1[i][0];
            step3.y=step2.y+next1[i][1];
            if(step3.x>=0&&step3.x<r&&step3.y>=0&&step3.y<c&&!num[step3.x][step3.y][(step2.sum+1)%k])
            {
                if(map[step3.x][step3.y]=='.'||map[step3.x][step3.y]=='G'||map[step3.x][step3.y]=='Y')
                {
                    step3.sum=step2.sum+1;
                    q.push(step3);
                    num[step3.x][step3.y][(step3.sum)%k]=1;
                }
                if(map[step3.x][step3.y]=='#'&&(step2.sum+1)%k==0)
                {
                    step3.sum=step2.sum+1;
                    q.push(step3);
                    num[step3.x][step3.y][0]=1;
                }
            }
        }
        q.pop();
    }
    return 0;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       memset(num,0,sizeof(num));
       int x1,y1,x2,y2;
       scanf("%d%d%d",&r,&c,&k);
      for(int i=0;i<r;i++)
        scanf("%s",map[i]);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
        {
            if(map[i][j]=='Y')
                {
                    x1=i;y1=j;
                }
            if(map[i][j]=='G')
                {
                    x2=i;y2=j;
                }
        }
        int flag=bfs(x1,y1,x2,y2);
        if(flag)
            printf("%d\n",flag);
        else
            printf("Please give me another chance!\n");
   }
    return 0;
}
