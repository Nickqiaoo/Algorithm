#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int m, n;
char ch[22][22];
int num[22][22];
typedef pair<int, int>P;
int next1[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int bfs(int ax, int ay, int ex, int ey)
{
	queue<P>q; int nx, ny;
	while (!q.empty())
		q.pop();
	q.push(P(ax, ay));
	num[ax][ay] = 1;
	while (!q.empty())
	{
		P fx = q.front();
		if (fx.first == ex&&fx.second == ey)
			return num[ex][ey];
		for (int i = 0; i <=3; i++)
		{
			nx = fx.first + next1[i][0];
			ny = fx.second + next1[i][1];
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n)
			{
				if (ch[nx][ny] == 'T')
				{
					q.push(P(nx, ny));
					num[nx][ny] = num[fx.first][fx.second] + 1;
				}
				if (ch[nx][ny] == '.')
				{
					if (!num[nx][ny])
					{
						num[nx][ny] = num[fx.first][fx.second] + 1;
						q.push(P(nx, ny));
					}
				}
				if (ch[nx][ny] == '|')
				{
					
						if (num[fx.first][fx.second] % 2 != 0)
						{
							if (i == 1 && nx + 1 < m&& (ch[nx + 1][ny] == '.' || ch[nx + 1][ny] == 'T'))
							{
								if (num[nx + 1][ny])
								{
									if (num[nx + 1][ny] > num[fx.first][fx.second] + 1)
										num[nx + 1][ny] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx + 1][ny] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx + 1, ny));
									}
							}
							if (i == 3 && nx - 1 >= 0 && (ch[nx -1][ny] == '.'|| ch[nx - 1][ny] == 'T'))
							{
								if (num[nx - 1][ny])
								{
									if (num[nx - 1][ny] > num[fx.first][fx.second] + 1)
										num[nx - 1][ny] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx - 1][ny] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx - 1, ny));
									}
							}
							if (i == 2 && ny - 1 >= 0 && (ch[nx][ny - 1] == '.' || ch[nx][ny - 1] == 'T') )
							{
								if (num[nx][ny - 1])
								{
									if (num[nx][ny - 1] > num[fx.first][fx.second] +2)
										num[nx][ny - 1] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx][ny - 1] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx, ny - 1));
									}
							}
							if (i == 0 && ny + 1 < n && (ch[nx][ny+1] == '.' || ch[nx][ny+1] == 'T') )
							{
								if (num[nx][ny + 1])
								{
									if (num[nx][ny + 1] > num[fx.first][fx.second] + 2)
										num[nx][ny + 1] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx][ny + 1] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx, ny + 1));
									}
							}
						}
						if (num[fx.first][fx.second] % 2 == 0)
						{
							if (i == 2 && ny - 1 >= 0&&(ch[nx][ny-1]=='.'|| ch[nx][ny - 1] == 'T'))
							{
								if (num[nx][ny - 1])
								{
									if (num[nx][ny - 1] > num[fx.first][fx.second] + 1)
										num[nx][ny - 1] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx][ny - 1] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx, ny - 1));
									}
							}
							if (i == 0 && ny + 1 < n && (ch[nx][ny + 1] == '.' || ch[nx][ny + 1] == 'T') )
							{
								if (num[nx][ny + 1])
								{
									if (num[nx][ny + 1] > num[fx.first][fx.second] + 1)
										num[nx][ny + 1] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx][ny + 1] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx, ny + 1));
									}
							}
							if (i == 1 && nx + 1 < m&&(ch[nx + 1][ny] == '.'|| ch[nx + 1][ny] == 'T') )
							{
								if (num[nx + 1][ny])
								{
									if (num[nx + 1][ny] > num[fx.first][fx.second] + 2)
										num[nx + 1][ny] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx + 1][ny] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx + 1, ny));
									}
							}
							if (i == 3 && nx - 1 >= 0 && (ch[nx - 1][ny] == '.' || ch[nx - 1][ny] == 'T') )
							{
								if (num[nx - 1][ny])
								{
									if (num[nx - 1][ny] > num[fx.first][fx.second] + 2)
										num[nx - 1][ny] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx - 1][ny] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx - 1, ny));
									}
							}
						}
					
				}
				if (ch[nx][ny] == '-')
				{
					
						if (num[fx.first][fx.second] % 2 == 0)
						{
							if (i == 1 && nx + 1 < m&& (ch[nx + 1][ny] == '.' || ch[nx + 1][ny] == 'T')  )
							{
								if (num[nx + 1][ny])
								{
									if (num[nx + 1][ny] > num[fx.first][fx.second] + 1)
										num[nx + 1][ny] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx + 1][ny] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx + 1, ny));
									}
							}
							if (i == 3 && nx - 1 >= 0 && (ch[nx - 1][ny] == '.' || ch[nx - 1][ny] == 'T'))
							{
								if (num[nx - 1][ny])
								{
									if (num[nx - 1][ny] > num[fx.first][fx.second] + 1)
										num[nx - 1][ny] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx - 1][ny] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx - 1, ny));
									}
							}
							if (i == 2 && ny - 1 >= 0 && (ch[nx][ny - 1] == '.' || ch[nx][ny - 1] == 'T') )
							{
								if (num[nx][ny - 1])
								{
									if (num[nx][ny - 1] > num[fx.first][fx.second] + 2)
										num[nx][ny - 1] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx ][ny-1] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx, ny-1));
									}
							}
							if (i == 0 && ny + 1 < n&& (ch[nx][ny + 1] == '.' || ch[nx][ny + 1] == 'T'))
							{
								if (num[nx][ny + 1])
								{
									if (num[nx][ny + 1] > num[fx.first][fx.second] + 2)
										num[nx][ny + 1] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx][ny + 1] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx, ny + 1));
									}
							}
						}
						if (num[fx.first][fx.second] % 2 != 0)
						{
							if (i == 2 && ny - 1 >= 0 && (ch[nx][ny - 1] == '.'|| ch[nx][ny - 1] == 'T') )
							{
								if (num[nx][ny - 1])
								{
									if (num[nx][ny - 1] > num[fx.first][fx.second] + 1)
										num[nx][ny - 1] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx][ny - 1] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx, ny - 1));
									}
							}
							if (i == 0 && ny + 1 < n&&(ch[nx][ny + 1] == '.'|| ch[nx][ny + 1] == 'T'))
							{
								if (num[nx][ny + 1])
								{
									if (num[nx][ny + 1] > num[fx.first][fx.second] + 1)
										num[nx][ny + 1] = num[fx.first][fx.second] + 1;
								}
									else
									{
										num[nx][ny + 1] = num[fx.first][fx.second] + 1;
										num[nx][ny] = 1;
										q.push(P(nx, ny + 1));
									}
							}
							if (i == 1 && nx + 1 < m && (ch[nx + 1][ny] == '.' || ch[nx + 1][ny] == 'T') )
							{
								if (num[nx + 1][ny])
								{
									if (num[nx + 1][ny] > num[fx.first][fx.second] + 2)
										num[nx + 1][ny] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx + 1][ny] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx + 1, ny));
									}
							}
							if (i == 3 && nx - 1 >= 0 && (ch[nx - 1][ny] == '.' || ch[nx - 1][ny] == 'T') )
							{
								if (num[nx - 1][ny])
								{
									if (num[nx - 1][ny] > num[fx.first][fx.second] + 2)
										num[nx - 1][ny] = num[fx.first][fx.second] + 2;
								}
									else
									{
										num[nx - 1][ny] = num[fx.first][fx.second] + 2;
										num[nx][ny] = 1;
										q.push(P(nx - 1, ny));
									}
							}
						}
					
				}

			}
		}
		q.pop();
	}
}
int main()
{
	int a, b, c, d;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		memset(num, 0, sizeof(num));
		for (int i = 0; i < m; i++)
			scanf("%s", ch[i]);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (ch[i][j] == 'S')
				{
					a = i; b = j;
				}
				if (ch[i][j] == 'T')
				{
					c = i; d = j;
				}
			}
		printf("%d\n", bfs(a, b, c, d) - 1);
	}
	return 0;	
}