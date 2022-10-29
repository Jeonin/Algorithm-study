#include <iostream>
#include <queue>
#define  MAX 201
using namespace std;
int n;
int r1, c1, r2, c2;
int moveX[6] = { 2, 2, 0, 0, -2, -2 };
int moveY[6] = { 1, -1, 2, -2, 1, -1 };
bool visited[MAX][MAX];

struct info
{
	int x;
	int y;
	int cnt;
};
void bfs()
{
	queue <info>q;
	q.push({ r1, c1, 0 });
	visited[r1][c1] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		
		for (int i = 0; i < 6; ++i)
		{
			int nx = x + moveX[i];
			int ny = y + moveY[i];

			if (nx == r2 && ny == c2)
			{
				cout << cnt + 1;
				return;
			}

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;

			q.push({ nx, ny, cnt + 1 });
			visited[nx][ny] = true;
		}	
	}

	cout << -1;
	return;
}
int main()
{
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	bfs();
	return 0;
}