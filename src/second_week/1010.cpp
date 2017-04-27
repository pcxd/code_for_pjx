#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cmath>
#include<cstring>


using namespace std;

char maze[8][8];
int vis[8][8];

int n, m, T;

bool ans;

void dfs(int x, int y, int t)
{
	if(maze[x][y] == 'D')
	{
		if(t == T)
			ans = true;
		return;
	}
	if(t == T)
		return;


	if(ans == false)
	{

	if(x+1 < n && vis[x+1][y] == 0)
	{

		vis[x][y] = 1;

		dfs(x+1, y, t+1);

		vis[x][y] = 0;
	}
	if(x-1 >= 0 && vis[x-1][y] == 0)
	{
		vis[x][y] = 1;
		dfs(x-1, y, t+1);
		vis[x][y] = 0;
	}

	if(y+1 < m && vis[x][y+1] == 0)
	{
		vis[x][y] = 1;
		dfs(x, y+1, t+1);
		vis[x][y] = 0;

	}
	if(y-1 >= 0 && vis[x][y-1] == 0)
	{
		vis[x][y] = 1;
		dfs(x, y-1, t+1);
		vis[x][y] = 0;

	}

	}
}


int main()
{
	while(cin >> n >> m >> T, n || m || T)
	{
	memset(vis, 0, sizeof(vis));

	int i, j;
	int sx, sy, ex, ey;

	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
		{
			cin >> maze[i][j];
			if(maze[i][j] == 'X')
				vis[i][j] = 1;
			else if(maze[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if(maze[i][j] == 'D')
			{
				ex = i;
				ey = j;

			}
		}
	ans = false;

	int eo1 = (ex + ey - sx - sy) & 1;
	int eo2 = T & 1;
//∆Ê≈º
	if(n && m && T && eo1 == eo2)
		dfs(sx, sy, 0);

	if(ans)
	cout << "YES" << endl;
	else cout << "NO" << endl;
	}
	return 0;
}
