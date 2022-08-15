#include <iostream>
#include <queue>
#include <memory.h>
#define	MAX 301

using namespace std;

int n, m;
int dist[MAX][MAX] = { 0 };
bool visited[MAX][MAX];
int move_x[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int move_y[8] = { -2, 2, -1, 1, -2, 2, -1, 1 };


void bfs(int start_x, int start_y)
{
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = true;
	dist[start_x][start_y] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nx = x + move_x[i];
			int ny = y + move_y[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < m && !visited[nx][ny])
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(void)

{
	cin >> n;
	
	int startx, starty;
	int endx, endy;

	

	while (n--)
	{
		memset(dist, 0, sizeof(int)*MAX*MAX);
		memset(visited, false , sizeof(bool)*MAX*MAX);

		cin >> m;

		cin >> startx >> starty;
		cin >> endx >> endy;

		bfs(startx, starty);

		cout << dist[endx][endy] << '\n';
	}


	return 0;
}