#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int n, m;
char maze[21][21];
int result = INT_MAX;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int cnt, int c1x, int c1y, int c2x, int c2y)
{
	if (result < cnt) return;
	if (cnt > 10) return;


	for (int i = 0; i < 4; ++i)
	{
		int c1nx = c1x + dx[i];
		int c1ny = c1y + dy[i];
		int c2nx = c2x + dx[i];
		int c2ny = c2y + dy[i];


		if ((c1nx < 0 || c1ny < 0 || c1nx >= n || c1ny >= m) && (c2nx < 0 || c2ny < 0 || c2nx >= n || c2ny >= m)) continue;

		if (c1nx < 0 || c1ny < 0 || c1nx >= n || c1ny >= m)
		{
			result = min(result, cnt);
			return;
		}
		
		if (c2nx < 0 || c2ny < 0 || c2nx >= n || c2ny >= m)
		{
			result = min(result, cnt);
			return;
		}

		if (maze[c1nx][c1ny] == '#')
		{
			c1nx = c1x;
			c1ny = c1y;
		}

		if (maze[c2nx][c2ny] == '#')
		{
			c2nx = c2x;
			c2ny = c2y;
		}

		dfs(cnt + 1, c1nx, c1ny, c2nx, c2ny);

	}
}
int main()
{
	cin >> n >> m;

	bool isfirst = false;
	int c1y, c1x, c2y, c2x;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];

			if (maze[i][j] == 'o' && isfirst == false)
			{
				c1x = i;
				c1y = j;
				isfirst = true;
			}
			else if (maze[i][j] == 'o' && isfirst == true)
			{
				c2x = i;
				c2y = j;
			}
		}
	}

	dfs(0, c1x, c1y, c2x, c2y);
	
	if (result > 10)
		cout << -1;
	else
		cout << result + 1;
	

	
	return 0;
}