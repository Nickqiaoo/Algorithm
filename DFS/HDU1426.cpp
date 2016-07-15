#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int map[9][9];
int num, ok;
struct node
{
    int x, y;
}q[81];
bool check(int k, int cur)
{
    for (int i = 0; i < 9; i++)
        if (map[q[cur].x][i] == k || map[i][q[cur].y] == k)
            return 0;
    int x = q[cur].x / 3 * 3;
    int y = q[cur].y / 3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (map[x + i][y + j] == k)
                return 0;
    return 1;
}
void dfs(int cur)
{
    if (cur == num)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 8; j++)
                printf("%d ", map[i][j]);
            printf("%d\n", map[i][8]);
        }
        ok = 1;
        return;
    }
    else
    {
        for(int i=1;i<=9;i++)
            if (check(i, cur) && !ok)
            {
                map[q[cur].x][q[cur].y] = i;
                dfs(cur + 1);
                map[q[cur].x][q[cur].y] = 0;
            }
    }
    return;
}
int main()
{
    char s;
    int cas = 0;
    while (cin>>s)
    {
        num = 0;
        if (s == '?')
            map[0][0] = 0;
        else
            map[0][0] = s - '0';
        for(int i=0;i<9;i++)
            for (int j = 0; j < 9; j++)
            {
                if(!(i==0&&j==0))
                cin >> s;
                if (s == '?')
                {
                    map[i][j] = 0;
                    q[num].x = i;
                    q[num].y = j;
                    num++;
                }
                else
                    map[i][j] = s - '0';
            }
        ok = 0;
        if (cas++)
            printf("\n");
        dfs(0);
    }
    return 0;
}
