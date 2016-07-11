#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int c1[305], c2[305];
int a[17] = { 1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289 };
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i <= n; i++)//第一个括号的项数初始化为1
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for (int i = 2; i <= n; i++)//计算第2到n个式子
        {
            for (int j = 0; j <= n; j++)//计算每一项相乘
                for (int k = 0; k + j <= n; k += i)//数组下标表示幂
                    c2[k + j] += c1[j];
            for (int j = 0; j <= n; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        printf("%d\n", c1[n]);
    }
    return 0;
}
