#include <iostream>
#include <queue>
#include <climits>
#define MAX 101
using namespace std;
int map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int n, m, h;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int MinDay = INT_MIN;
struct info
{
	int z;
	int x;
	int y;	
	int day;
};

queue<info> q;

int main()
{
	cin >> n >> m >> h;
	bool check = false;

	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j][k];

				if (map[i][j][k] == 1)
				{
					q.push({ k, i, j, 0 });
					visited[i][j][k] = true;
				}

				else if (map[i][j][k] == -1)
					visited[i][j][k] = true;

				else
					check = true;
			}
		}
	}

	if (!check)
	{
		cout << 0;
		return 0;
	}

	int cnt = 0;

	if (!q.empty())
	{
		auto dir = q.front();
		q.pop();

		cnt = max(cnt, dir.day);

		for (int i = 0; i < 6; ++i)
		{
			int nx = dir.x + dx[i];
			int ny = dir.y + dy[i];
			int nz = dir.z + dz[i];


			if (nx >= 0 && ny >= 0 && nz >= 0 &&
				nx < m && ny < n && nz < h &&
				!visited[nx][ny][nz])
			{
				q.push({ nx, ny, nz, dir.day + 1 });
				visited[nx][ny][nz] = true;
			}
		}

	
	}

	
	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!visited[i][j][k])
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}