#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int c1[10050], c2[10050];
int main()
{
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        if (a == 0 && b == 0 && c == 0)
            break;
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for (int i = 0; i <= a; i++)
            c1[i] = 1;
        for (int i = 0; i <= a; i++)
            for (int j = 0; j <= b; j++)
                c2[i + 2 * j] += c1[i];
        for (int i = 0; i <= (a + 2 * b); i++)
        {
            c1[i] = c2[i];
            c2[i] = 0;
        }
        for (int i = 0; i <= (a + 2 * b); i++)
            for (int j = 0; j <= c; j++)
                c2[i + 5 * j] += c1[i];
        for (int i = 0; i <= (a + 2 * b + 5 * c); i++)
            c1[i] = c2[i];
        for (int i = 0; i <= (a + 2 * b + 5 * c+1); i++)
            if (c1[i] == 0)
            {
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
