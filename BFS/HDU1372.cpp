#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
typedef pair<int,int> P;
int next1[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int num[10][10];
int bfs(int sx,int sy,int ex,int ey)
{
    queue<P>q;
    while(!q.empty())
        q.pop();
    q.push(P(sx,sy));
    num[sx][sy]=1;
    while(!q.empty())
    {
        P fx=q.front();
        if(fx.first==ex&&fx.second==ey)
            return num[ex][ey];
        for(int i=0;i<8;i++)
        {
            int nx=fx.first+next1[i][0],ny=fx.second+next1[i][1];
            if(nx>=1&&nx<=8&&ny>=1&&ny<=8&&!num[nx][ny])
            {
                q.push(P(nx,ny));
                num[nx][ny]=num[fx.first][fx.second]+1;
            }
        }
        q.pop();
    }
}
int main()
{
    string ch1,ch2;
    int a,b,c,d;
    while(cin>>ch1>>ch2)
    {
        memset(num,0,sizeof(num));
        b=ch1[0]-'a'+1;a=ch1[1]-'0';d=ch2[0]-'a'+1;c=ch2[1]-'0';
        cout<<"To get from "<<ch1<<" to "<<ch2<<" takes "<<bfs(a,b,c,d)-1<<" knight moves."<<endl;
    }
    return 0;
}
