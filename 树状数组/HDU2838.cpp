#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100001
using namespace std;
struct tree
{
	int t;
	long long sum;
}tree[MAXN];
int n;
int lowbit(int i)
{
	return i&(-i);
}
void update(int i, int s, int x)
{
	while (i <= n)
	{
		tree[i].t += x;
		tree[i].sum += s;
		i = i + lowbit(i);
	}
}
int queryx(int n)
{
	int ans = 0;
	while (n > 0)
	{
		ans += tree[n].t;
		n -= lowbit(n);
	}
	return ans;
}
long long  querysum(int n)
{
	long long ans = 0;
	while (n > 0)
	{
		ans += tree[n].sum;
		n -= lowbit(n);
	}
	return ans;
}
int main()
{
	while (~scanf("%d", &n))
	{
		long long ans = 0;
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			update(a, a, 1);
			long long k = i - queryx(a);
			if (k != 0)
			{
				long long k1 = querysum(n) - querysum(a);
				ans += k*a + k1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}