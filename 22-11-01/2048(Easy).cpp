#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;
int n;
int board[MAX][MAX];
int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };


int dfs(int cnt)
{
	if (cnt == 5)
	{
		int result = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				result = max(result, board[i][j]);
			}
		}
		return result;
	}
	
	for (int i = 0; i < 4; ++i)
	{
		int nx = dx[i];
		int ny = dy[i];

		int cnt = 0;
		while (true)
		{
			bool IsMove = false;
			if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if(board[i][j] == 0) continue;

					if (board[i][j] == board[i+nx][j+ny] || board[i + nx][j + ny] == 0)
					{
						board[i + nx][j + ny] += board[i][j];
						board[i][j] = 0;
					}

				}
			}

			if (++cnt > 20)
				break;
		}
	}

	dfs(cnt + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	cout<<dfs(0);

	
	return 0;
}