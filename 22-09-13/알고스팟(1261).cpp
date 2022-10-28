#include <iostream>
#include <queue>
#include <string>
#include <climits>
#define MAX 101
using namespace std;

int n, m;
int maze[MAX][MAX];
int dist[MAX][MAX];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };


void bfs()
{
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	dist[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + moveX[i];
			int ny = y + moveY[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
			{
				if (maze[nx][ny] == 1)
				{
					if (dist[nx][ny] > dist[x][y] + 1)
					{
						dist[nx][ny] = dist[x][y] + 1;
						q.emplace(nx, ny);
					}
				}
				else if (maze[nx][ny] == 0)
				{
					if (dist[nx][ny] > dist[x][y])
					{
						dist[nx][ny] = dist[x][y];
						q.emplace(nx, ny);
					}
				}

			}		
		}
	}
}
int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); ++j)
		{
			maze[i][j] = str[j] - '0';
			dist[i][j] = INT_MAX;
		}
	}

	bfs();
	
	cout << dist[m-1][n-1];

	return 0;
}
