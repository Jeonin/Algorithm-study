#include <iostream>
#include <string>
#include <queue>
#include <climits>
#include <algorithm>
#include <memory.h>
#define MAX 1'001

using namespace std;
int n, m;
int maze[MAX][MAX];
bool visited[MAX][MAX][2];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0,  1,-1 };
int ans = INT_MAX;

struct info
{
	int x, y, cnt;
	bool Isbreak;
};

void bfs()
{
	queue<info> q;
	q.push({ 1, 1, 1, false});
	visited[1][1][0] = true;
	

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		bool check = q.front().Isbreak;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx == n && ny == m)
			{
				ans = min(ans, cnt + 1);
				return;
			}

			if (nx == 2 && ny == 4)
			{
				int a = 0;
			}


			//범위 밖에 나가거나, 방문을 했거나, 벽이 있을때 스킵
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (maze[nx][ny] == 0)
			{
				if (visited[nx][ny][0] == false)
				{
					q.push({ nx, ny, cnt + 1, check });
					visited[nx][ny][0] = true;
				}
				else if (visited[nx][ny][1] == false)
				{
					q.push({ nx, ny, cnt + 1, !check });
					visited[nx][ny][1] = true;
				}
				
			}
			else if(maze[nx][ny] == 1 && check == false && visited[nx][ny][0] == false)
			{		
				q.push({ nx, ny, cnt + 1, !check });
				visited[nx][ny][1] = true;
			}

		
		
		}
	}

	memset(&visited, false, sizeof(visited));
}



int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; ++j)
		{
			maze[i][j + 1] = str[j] - '0';
		}
	}

	bfs();


	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;
	return 0;
}