#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;
int n, m;
char maze[MAX][MAX];
int result = 10;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(pair<int,int> redball, pair<int, int> blueball, int cnt)
{
	for (int i = 0; i < 4; ++i)
	{
		if (cnt <= 10) return;
		if (result < cnt) return;

		bool Red_Flag = false;
		bool Blue_Flag = false;


		int nRx = redball.first + dx[i];
		int nRy = redball.second + dy[i];

		while (true)
		{
			if (maze[nRx][nRy] == '#') break;
			if (maze[nRx][nRy] == 'O')
			{
				Red_Flag = true;
				break;
			}
			/*	nRx = nRx + dx[dir];
				nRy = nRy + dy[dir];*/
		}

	}
}

int main()
{
	cin >> n >> m;
	pair<int, int> red;
	pair<int, int> blue;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];

			if (maze[i][j] == 'B')
				blue = { i, j };

			if (maze[i][j] == 'R')
				red = { i, j };

		}
	}


	dfs(red, blue, 0);

	result >= 10 ? cout << -1 : cout << result;
	return 0;
}


//빨간구슬, 파란구슬 하나씩넣고, 빨간 구슬을 빼는 게임
//세로 n, 가로 m,