#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int pre[5000];
struct Edge
{
    int u, v, w,t;
}edge[5000];
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int find(int x)
{
    if (pre[x] == x)
        return x;
    else
        return pre[x] = find(pre[x]);
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
            pre[i] = i;
        int sum = 0, num = 0;
        for (int i = 0; i < (n*(n - 1)) / 2; i++)
        {
            scanf("%d%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w, &edge[i].t);
            if (edge[i].t == 1)
                edge[i].w = 0;
        }
        sort(edge, edge + (n*(n - 1)) / 2, cmp);
        for (int i = 0; i <(n*(n - 1)) / 2; i++)
        {
            if (find(edge[i].u) != find(edge[i].v))
            {
                if(!edge[i].t)
                sum += edge[i].w;
                pre[find(edge[i].v)] = find(edge[i].u);
                num++;
            }
        }
            printf("%d\n", sum);

    }
    return 0;
}
