#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
using namespace std;  
#define maxn 9999999  
int map[102][102],dist[102];  
bool vis[102];  
int main()  
{  
    int n, m;  
    int a, b, c;  
    while (scanf("%d%d", &n, &m) != EOF)  
    {  
        if (n == 0 && m == 0)  
            break;  
        for(int i=1;i<=n;i++)  
            for(int j=1;j<=n;j++)  
                map[i][j] = map[i][j] = maxn;   
        for (int i = 0; i < m; i++)  
        {  
            scanf("%d%d%d", &a, &b, &c);  
            map[a][b] = map[b][a] = c;  
        }  
        for (int i = 1; i <= n; i++)  
        {  
            dist[i] = map[1][i];  
            vis[i] = 0;  
        }  
        dist[1] = 0;  
        vis[1] = 1;  
        for (int i = 1; i < n; i++)  
        {  
            int mind = maxn,temp;  
            for(int j=1;j<=n;j++)  
                if (!vis[j] && dist[j] < mind)  
                {  
                    mind = dist[j];  
                    temp = j;  
                }  
            vis[temp] = 1;  
            for (int j = 1; j <= n; j++)  
                if (!vis[j] && (dist[temp] + map[temp][j] < dist[j]))  
                    dist[j] = dist[temp] + map[temp][j];  
        }  
        printf("%d\n", dist[n]);  
    }  
    return 0;  
} 