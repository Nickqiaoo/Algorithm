#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1 << 30;
int map[27][27];//map��ͼ
int d[27];//��¼ÿ2��������СȨֵ
bool visit[27];//��¼���Ƿ����
int main()
{
    int  m, n, minn, temp, sum;
    char ch;
    //freopen("F:in.txt", "r", stdin);
    while (~scanf("%d", &n) && n)
    {
        memset(map,0x1f,sizeof(map));
        memset(d, 0, sizeof(d));
        memset(visit, 1, sizeof(visit));
        for (int i = 1; i < n; i++)
        {
            getchar();
            scanf("%c", &ch);
            scanf("%d", &m);
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &ch);
                scanf("%c", &ch);
                scanf("%d", &temp);
                map[i - 1][ch - 'A'] = temp;
                map[ch - 'A'][i - 1] = temp;
            }
        }
        for (int i = 1; i < n; i++)
            d[i] = map[i][0];//��ʼ����һ���㵽ʣ�µ�ľ���
        sum = 0;
        visit[0] = 0;
        for (int i = 1; i < n; i++)
        {
            minn = INF;
            for(int j=0;j<n;j++)
                if (visit[j] && d[j] < minn)
                {
                    minn = d[j];
                    temp = j;
                }////�ҳ���СȨֵ����¼λ��
            visit[temp] = 0;
            sum += minn;
            for (int j = 0; j < n; j++)
            {
                if (visit[j] && d[j] > map[j][temp])//����Ȩֵ
                    d[j] = map[j][temp];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
