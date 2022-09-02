#include <iostream>	
#include <queue>
#include <memory.h>
#define MAX 51
using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[8] = { 1, 1, 1, -1, -1, -1 ,0 , 0 };
int dy[8] = { 1, -1, 0, 1, -1, 0, 1, -1 };

void bfs(int startx, int starty)
{
	queue<pair<int, int>> q;
	q.push({ startx, starty });
	visited[startx][starty] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && map[nx][ny])
			{
				visited[nx][ny] = true;
				q.emplace(nx, ny);
			}
		}

	}


}

int main()
{
	while (true)
	{
		
		cin >> n >> m;

		if (!n && !m)
			break;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (map[i][j] && !visited[i][j])
				{
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';

		memset(&visited, false, sizeof(visited));
		memset(&map, 0, sizeof(map));
	}

	return 0;
}