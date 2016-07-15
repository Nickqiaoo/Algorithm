#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#define N 10005
using namespace std;
bool vis[N], del[10];//记录已经访问的数字，不能使用的数字
int n, pre[N];//记录前置余数
char text[N];//记录输出
bool bfs()
{
    queue<int>q;
    q.push(0);
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 10; i++)
        {
            if(del[i]==1||cur==0&&i==0)
                continue;
            int yu = (cur * 10 + i) % n;
            if(vis[yu])//出现相同余数保存之前较小的
                continue;
            text[yu] = '0' + i;
            vis[yu] = 1;
            pre[yu] = cur;
            q.push(yu);
            if (yu == 0)
                return 1;
        }
    }
    return 0;
}
void print()
{
    string ans;
    int p = 0;
    while (p != 0 || ans.empty())
    {
        ans += text[p];
        p = pre[p];
    }
    reverse(ans.begin(), ans.end());
    cout << ans<<endl;
}
int main()
{
    int m, cas = 0;
    while (~scanf("%d%d", &n, &m))
    {
        memset(vis, 0, sizeof(vis));
        memset(del, 0, sizeof(del));
        while (m--)
        {
            int k;
            scanf("%d", &k);
            del[k] = 1;
        }
        printf("Case %d: ", ++cas);
        if (!bfs())
            printf("-1\n");
        else
            print();
    }
    return 0;
}
