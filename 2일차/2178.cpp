#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 101
using namespace std;
int n, m;
int graph[MAX][MAX];
bool check[MAX][MAX];
int dist[MAX][MAX];
int moveX[4] = { -1, 1, 0, 0 };
int moveY[4] = { 0, 0, -1, 1 };


void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	dist[x][y] = 1;
	check[x][y] = true;
	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + moveX[i];
			int ny = y + moveY[i];


			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !check[nx][ny])
			{
				if (graph[nx][ny] == 1)
				{
					q.push({ nx, ny });
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}

}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; ++j)
		{
			graph[i][j] = str[j] - '0';
		}
	}

	bfs(0, 0);

	cout << dist[n - 1][m - 1];

	return 0;
}