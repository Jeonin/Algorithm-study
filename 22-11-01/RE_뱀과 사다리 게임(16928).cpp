#include <iostream>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
array<int, 101> board;
bool visited[101];


void dfs()
{
	queue<pair<int, int>> q;
	q.emplace(1, 0);
	visited[1] = true;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();


		for (int i = 1; i <= 6; ++i)
		{
			int nx = x + i;
			
			if (nx == 100)
			{
				cout << cnt + 1;
				exit(0);
			}

			if(visited[nx] || nx > 100) continue;

			if (board[nx] != 0)
			{
				q.emplace(board[nx], cnt + 1);
				visited[board[nx]] = true;
			}
			else
			{
				q.emplace(nx, cnt + 1);
				visited[nx] = true;
			}
			
		}
		
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n + m; ++i)
	{
		int begin, end;
		cin >> begin >> end;
		board[begin] = end;
	}

	dfs();
	return 0;
}