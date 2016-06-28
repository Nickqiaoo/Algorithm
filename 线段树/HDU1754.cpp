#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int MAX(int a, int b)
{
    return a > b ? a : b;
}
const int MAXN = 200001;
struct
{
    int l, r, m;
}tree[MAXN*4];
int a[MAXN];
void creat(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if (l == r)
    {
        tree[root].m = a[l];
        return;
    }
    int m = (l + r) / 2;
    creat(root * 2, l, m);
    creat(root * 2 + 1, m + 1, r);
    tree[root].m = MAX(tree[root * 2].m, tree[root * 2 + 1].m);
}
void update(int root, int n, int v)
{
    if (tree[root].l == tree[root].r)
    {
        tree[root].m = v;
        return;
    }
    if (n <= tree[root * 2].r)
        update(root * 2, n, v);
    else
        update(root * 2 + 1, n, v);
    tree[root].m = MAX(tree[root * 2].m, tree[root * 2 + 1].m);
}
int query(int root, int l, int r)
{
    if (tree[root].l == l&&tree[root].r == r)
        return tree[root].m;
    int s;
    if (r <= tree[root * 2].r)
        s = query(root * 2, l, r);
    else if (l >= tree[root * 2 + 1].l)
        s = query(root * 2 + 1, l, r);
    else s = MAX(query(root * 2, l, tree[root * 2].r), query(root * 2 + 1, tree[root * 2 + 1].l, r));
    return s;
}
int main()
{
    int n, m,x1, x2;
    char s[2];
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        creat(1, 1, n);
        while (m--)
        {
            scanf("%s%d%d", s, &x1, &x2);
            if (s[0] == 'Q')
                printf("%d\n", query(1, x1, x2));
            else
                update(1, x1, x2);
        }
    }
    return 0;
}
