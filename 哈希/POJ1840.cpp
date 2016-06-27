#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1030307
int hashn[maxn], nextn[maxn];
int num[maxn];
using namespace std;
int main()
{
    int a, b, c, d, e;
    while (~scanf("%d%d%d%d%d", &a, &b, &c, &d, &e))
    {
        memset(hashn, -1, sizeof(hashn));
        int mm = 0;
        for (int i = -50; i <= 50; i++)
            if (i != 0)
                for (int j = -50; j <= 50; j++)
                    if (j != 0)
                        for (int k = -50; k <= 50; k++)
                            if (k != 0)
                            {
                                int t = a*i*i*i + b*j*j*j + c*k*k*k;
                                num[mm] = t;
                                int key = t%maxn;
                                key = (key + maxn) % maxn;
                                nextn[mm] = hashn[key];
                                hashn[key] = mm;
                                mm++;
                            }
        int sum = 0;
        for (int i = -50; i <= 50; i++)
            if (i != 0)
                for (int j = -50; j <= 50; j++)
                    if (j != 0)
                    {
                        int t = -e*i*i*i - d*j*j*j;
                        int key = t%maxn;
                        key = (key + maxn) % maxn;
                        int m = hashn[key];
                        while (m != -1)
                        {
                            if (t == num[m])
                                sum++;
                            m = nextn[m];
                        }
                    }
        printf("%d\n", sum);
    }
    return 0;
}
