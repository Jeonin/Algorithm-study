#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int n, l, r;
int nation[51][51];
bool visited[51][51];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int startx, int starty)
{
	queue<pair<int, int>> q;
	q.emplace(startx, starty);

	visited[startx][starty] = true;

	int sum = nation[startx][starty];
	int cnt = 1;
	bool isOpen = false;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;

			int comp = abs(nation[x][y] - nation[nx][ny]);

			if (comp >= l && comp <= r)
			{
				visited[nx][ny] = true;
				q.emplace(nx, ny);
				sum += nation[nx][ny];
				cnt++;

				isOpen = true;
			}
		}
	}

	// 열린 국경선이 하나도 없으면 0을 반환
	if (isOpen == false)
		return 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (visited[i][j] == true)
			{
				nation[i][j] = sum / cnt;
			}
		}
	}

	return 1;
	
}
int main()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> nation[i][j];
		}
	}

	int cnt = 0;

	while (true)
	{
		int isopened = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visited[i][j] == false)
					isopened += bfs(i, j);
			}
		}

		//국경선이 하나도 안열렸으면 종료
		if (isopened == 0)
		{
			cout << cnt;
			break;
		}

		cnt++;
		memset(&visited, false, sizeof(visited));
	}
	

	return 0;
}