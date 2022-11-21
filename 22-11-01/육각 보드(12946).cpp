#include <iostream>
#include <algorithm>
using namespace std;
int n;
char board[51][51];
int color[51][51];
int dx[6] = { -1, -1, 0, 1, 1, 0 };
int dy[6] = {  0,  1, 1, 0,-1,-1 };
int result = 0;

void Print(int x, int y, int cnt)
{
	color[x][y] = cnt;
	result = max(cnt, 1);

	for (int i = 0; i < 6; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (board[nx][ny] == 'X')
		{
			if (color[nx][ny] == -1)
			{
				Print(nx, ny, 1 - cnt);
				result = max(result, 2);
			}
			else if(color[nx][ny] == cnt)
			{
				result = max(result, 3);
				cout << 3 << '\n';
				exit(0);
			}
			
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
			color[i][j] = -1; // 아무 색도 칠해지지 않은 상황
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == 'X' && color[i][j] == -1)
			{
				Print(i, j, 0);
			}		
		}
	}
	
	cout << result;
	return 0;
}