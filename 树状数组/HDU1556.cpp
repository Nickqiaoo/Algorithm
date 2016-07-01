#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 100005
int n, tree[MAXN];
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
		memset(tree, 0, sizeof(tree));
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			update(a, 1);//a以后元素+1
			update(b + 1, -1);//b以后元素-1
		}
		for (int i = 1; i < n; i++)
			printf("%d ", query(i));
		printf("%d\n", query(n));
	}
	return 0;
}
