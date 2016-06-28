#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define N 50005
using namespace std;
int num[N];
struct Tree
{
    int l;
    int r;
    int sum;
}tree[N*4];
void build(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if (tree[root].l == tree[root].r)
    {
        tree[root].sum = num[l];
        return;
    }
    int mid = (l + r) / 2;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
    tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
}
void update(int root, int pos, int val)
{
    if (tree[root].l == tree[root].r)
    {
        tree[root].sum = val;
        return;
    }
    int mid = (tree[root].l + tree[root].r) / 2;
    if (pos <= mid)
        update(root * 2, pos, val);
    else
        update(root * 2 + 1, pos, val);
    tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
}
int query(int root, int L, int R)
{
    if (L <= tree[root].l&&R >= tree[root].r)
        return tree[root].sum;
    int mid = (tree[root].l + tree[root].r) / 2, ret = 0;
    if (L <= mid)
        ret += query(root * 2, L, R);
    if (R > mid)
        ret += query(root * 2 + 1, L, R);
    return ret;
}
int main()
{
    int ca, cas = 1, n, Q, a, b;
    char str[10];
    scanf("%d", &ca);
    while (ca--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        build(1, 1, N);
        printf("Case %d:\n", cas++);
        while (scanf("%s", str), strcmp(str, "End"))
        {
            scanf("%d%d", &a, &b);
            if (strcmp(str, "Query") == 0)
            {
                if (a > b)
                    swap(a, b);
                printf("%d\n", query(1, a, b));
            }
            else if (strcmp(str, "Add") == 0)
            {
                num[a] = num[a] + b;
                update(1, a, num[a]);
            }
            else if (strcmp(str, "Sub") == 0)
            {
                num[a] = num[a] - b;
                update(1, a, num[a]);
            }
        }
    }
    return 0;
}
