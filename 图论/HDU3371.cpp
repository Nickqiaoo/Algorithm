#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int pre[501];
struct Edge
{
	int u, v, w;
}edge[25001];
int  cmp(Edge a, Edge b)
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
	int q,n,m,k,k1,k2,k3,pa,pb;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
			pre[i] = i;
		int sum = 0, num = 0;
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d", &k1,&k2);
			k1--;
			while (k1--)
			{
				scanf("%d",&k3);
				pa = find(k2); pb = find(k3);
				if (pa != pb)
				{
					pre[pb] = pa;
					num++;
				}
			}

		}
		sort(edge, edge + m, cmp);
		for (int i = 0; num<n-1&&i <m; i++)
		{
			pa = find(edge[i].u); pb = find(edge[i].v);
			if (pa != pb)
			{
				sum += edge[i].w;
				pre[pa] = pb;
				num++;
			}
		}
		if (num != n - 1)
			printf("-1\n");
		else
			printf("%d\n", sum);

	}
	return 0;
}
