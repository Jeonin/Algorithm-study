#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 51
using namespace std;

int t, row, col, k;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int startx, int starty)
{
	queue < pair<int, int>> q;
	visited[startx][starty] = true;
	q.emplace(startx, starty);


	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || ny < 0 || nx >= col || ny >= row || visited[nx][ny] == true || arr[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			q.emplace(nx, ny);
		}
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> col >> row >> k;

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < col; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if (arr[i][j] == 1 && visited[i][j] == false)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';

		memset(&visited, false, sizeof(visited));
		memset(&arr, 0, sizeof(arr));
	}
	return 0;
}