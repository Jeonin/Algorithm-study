#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1'001
using namespace std;
int n, m;
int maze[MAX][MAX];


void bfs()
{
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	
	int Candy[MAX][MAX]{};
	
	Candy[1][1] = maze[1][1];

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n && y == m)
		{
			cout << Candy[n][m];
			return;
		}

		if (x + 1 > 0 && x + 1 <= n)
		{
			q.emplace(x + 1, y);
			Candy[x + 1][y] = max(Candy[x+1][y], Candy[x][y] + maze[x + 1][y]);
		}

		if (y + 1 > 0 && y + 1 <= m)
		{
			q.emplace(x, y + 1);
			Candy[x][y + 1] = max(Candy[x][y + 1], Candy[x][y] + maze[x][y + 1]);
		}

		if (x + 1 > 0 && x + 1 <= n && y + 1 > 0 && y + 1 <= m)
		{
			q.emplace(x + 1, y + 1);
			Candy[x + 1][y + 1] = max(Candy[x + 1][y + 1], Candy[x][y] + maze[x + 1][y + 1]);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> maze[i][j];
		}
	}

	bfs();

	return 0;
}