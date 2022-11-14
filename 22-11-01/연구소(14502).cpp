#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int maze[9][9];
int ans = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs()
{
	int copy[9][9];
	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			copy[i][j] = maze[i][j];

			if (copy[i][j] == 2)
			{
				q.emplace(i, j);
			}
		}
	}
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || copy[nx][ny] != 0) continue;
			copy[nx][ny] = 2;
			q.emplace(nx, ny);

		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (copy[i][j] == 0)
				cnt++;
		}
	}

	ans = max(ans, cnt);
}

void dfs(int cnt)
{
	if (cnt == 3) //세울 수 있는 벽의 수
	{		
		bfs();
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (maze[i][j] != 0) continue;

			maze[i][j] = 1;
			dfs(cnt + 1);
			maze[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];
		}
	}

	dfs(0);

	cout << ans;
	return 0;
}