#include <iostream>
#include <queue>
#include <string>
#define MAX 101
using namespace std;
int n, m;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct INFO
{
	int x;
	int y;
	int cnt;
};

void bfs(int startx, int starty)
{
	queue<INFO> q;
	q.push({ startx, starty, 1 });
	visited[startx][starty] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int count = q.front().cnt;

		q.pop();

		if (x + 1== n && y + 1== m)
		{
			cout << count;
			return;
		}
			

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
				!visited[nx][ny] && maze[nx][ny])
			{
				visited[nx][ny] = true;
				q.push({ nx, ny, count +1 });
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	string str[MAX];

	for (int i = 0; i < n; ++i)
		cin >> str[i];


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			maze[i][j] = str[i][j] - '0';	
	}

	bfs(0, 0);

	return 0;
}