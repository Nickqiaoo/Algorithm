#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
int n,m;
char map[105][105];
int next1[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
struct step
{
    int x,y,flag;
}step1[105][105];
int num[2][420];
typedef pair<int,int> P;
stack<P>st;
int bfs()
{
    queue<P> q;
    while(!q.empty())
        q.pop();
    q.push(P(0,0));
   if(map[0][0]>='1'&&map[0][0]<='9')
    step1[0][0].flag=(map[0][0]-'0')+1;
   else
    step1[0][0].flag=1;

    while(!q.empty())
    {
        P f=q.front();
        if(f.first==n-1&&f.second==m-1)
            return 1;
        for(int i=0;i<4;i++)
        {
            int nx=f.first+next1[i][0],ny=f.second+next1[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<=m&&!step1[nx][ny].flag)
            {
                if(map[nx][ny]=='.')
                {
                    q.push(P(nx,ny));
                    step1[nx][ny].flag=step1[f.first][f.second].flag+1;

                    step1[nx][ny].x=f.first;
                    step1[nx][ny].y=f.second;
                }
                if(map[nx][ny]>='1'&&map[nx][ny]<='9')
                {
                    q.push(P(nx,ny));
                    step1[nx][ny].flag=step1[f.first][f.second].flag+(map[nx][ny]-'0')+1;

                    step1[nx][ny].x=f.first;
                    step1[nx][ny].y=f.second;
                }
          }
          if(nx>=0&&nx<n&&ny>=0&&ny<=m&&step1[nx][ny].flag&&step1[nx][ny].flag>step1[f.first][f.second].flag+1)
          {
              if(map[nx][ny]=='.')
             {
                 step1[nx][ny].flag=step1[f.first][f.second].flag+1;
                    step1[nx][ny].x=f.first;
                    step1[nx][ny].y=f.second;
             }
              if(map[nx][ny]>='1'&&map[nx][ny]<='9')
                {
                    step1[nx][ny].flag=step1[f.first][f.second].flag+(map[nx][ny]-'0')+1;
                    step1[nx][ny].x=f.first;
                    step1[nx][ny].y=f.second;
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
        getchar();
       for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
        {
            scanf("%c",&map[i][j]);
            step1[i][j].flag=0;
        }
        getchar();
      }
        if(bfs())
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",step1[n-1][m-1].flag-1);
             int tx=n-1,ty=m-1;
            st.push(P(tx,ty));
            while(tx!=0||ty!=0)
            {
                int a=step1[tx][ty].y;
                tx=step1[tx][ty].x;
                ty=a;
                st.push(P(tx,ty));
            }
             if(map[0][0]>='1'&&map[0][0]<='9')
             {
                  for(int i=1;i<=map[tx][ty]-'0';i++)
                    printf("%ds:FIGHT AT (%d,%d)\n",step1[tx][ty].flag-1-(map[tx][ty]-'0')+i,tx,ty);
             }
            st.pop();
            tx=st.top().first;
            ty=st.top().second;
            st.pop();
            while(tx!=n-1||ty!=m-1)
            {
                if(map[tx][ty]>='1'&&map[tx][ty]<='9')
                {

                    printf("%ds:(%d,%d)->(%d,%d)\n",step1[tx][ty].flag-1-(map[tx][ty]-'0'),step1[tx][ty].x,step1[tx][ty].y,tx,ty);
                    for(int i=1;i<=map[tx][ty]-'0';i++)
                    printf("%ds:FIGHT AT (%d,%d)\n",step1[tx][ty].flag-1-(map[tx][ty]-'0')+i,tx,ty);
                }
                else
                 printf("%ds:(%d,%d)->(%d,%d)\n",step1[tx][ty].flag-1,step1[tx][ty].x,step1[tx][ty].y,tx,ty);
                 tx=st.top().first;
                 ty=st.top().second;
                 st.pop();
            }
            if(map[tx][ty]>='1'&&map[tx][ty]<='9')
                {
                    printf("%ds:(%d,%d)->(%d,%d)\n",step1[tx][ty].flag-1-(map[tx][ty]-'0'),step1[tx][ty].x,step1[tx][ty].y,tx,ty);
                    for(int i=1;i<=map[tx][ty]-'0';i++)
                    printf("%ds:FIGHT AT (%d,%d)\n",step1[tx][ty].flag-1-(map[tx][ty]-'0')+i,tx,ty);
                }
            else
                 printf("%ds:(%d,%d)->(%d,%d)\n",step1[tx][ty].flag-1,step1[tx][ty].x,step1[tx][ty].y,tx,ty);
                cout<<"FINISH"<<endl;
        }
        else
            cout<<"God please help our poor hero."<<endl<<"FINISH"<<endl;
   }
    return 0;
}
