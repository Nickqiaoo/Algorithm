#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, tree[1005];
int lowbit(int i)
{
	return i&(-i);
}
void update(int i, int x)
{
	while (i <= n)
	{
		tree[i] += x;
		i = i + lowbit(i);
	}
}
int query(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += tree[n];
		n = n - lowbit(n);
	}
	return sum;
}
int main()
{
	while (scanf("%d", &n) != EOF&&n)
	{
		int a, ans = 0;
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			update(a, 1);
			ans += i - query(a);
		}
		printf("%d\n", ans);
	}
	return 0;
}
