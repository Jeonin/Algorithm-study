#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int n, m;
char board[26][26];
bool visited[26][26];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 ,0 ,1, -1 };
int startx, starty;
bool Exist = false;

void dfs(int x, int y, int cnt)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx == startx && ny == starty && cnt >= 4)
		{
			cout << "Yes";
			exit(0);
			
		}

		if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] ||
			board[nx][ny] != board[startx][starty]) continue;

		dfs(nx, ny, cnt + 1);
	}

	visited[x][y] = false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			startx = i, starty = j;
			if(visited[i][j]) continue;		
			dfs(i, j, 1);
		}
	}

	cout << "No";
	return 0;

}