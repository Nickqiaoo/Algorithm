#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 7003
using namespace std;
int hashn[maxn], countn[maxn], n;
int maxit;
int ELFhash(char *key)//字符串hash
{
    long long h = 0;
    long long g;
    while (*key)
    {
        h = (h << 4) + *key++;
        g = h & 0xf0000000L;
        if (g)
            h^= g >> 24;
        h &= ~g;
    }
    return h;
}
void hashit(char *s)
{
    int k;
    while (*s == '0')
        s++;
    k = ELFhash(s);
    int t = k%maxn;
    while (hashn[t] != k&&hashn[t] != -1)
        t = (t + 10) % maxn;//开放地址法解决冲突
    if (hashn[t] == -1)
    {
        countn[t] = 1;
        hashn[t] = k;
    }
    else if (++countn[t] > maxit)
        maxit = countn[t];
    return;
}
int main()
{
    //freopen("C:\\in.txt", "r", stdin);
    char str[100];
    while (~scanf("%d",&n))
    {
        memset(hashn, -1, sizeof(hashn));
        getchar();
        maxit = 1;
        for (int i = 0; i < n; i++)
        {
            gets(str);
            hashit(str);
        }
        printf("%d\n", maxit);
    }
    return 0;
}
