#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 101
using namespace std;

int ladder, snake;
int maze[MAX];
bool visited[MAX];


void bfs()
{
	queue<pair<int, int>> q;
	q.emplace(1, 0);
	
	while (!q.empty())
	{
		int place = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nextPlace = place + (i + 1);

			if (nextPlace == 100)
			{
				cout << cnt + 1;
				return;
			}

			if (nextPlace > 100) continue;

			if (maze[nextPlace] != 0)
				nextPlace = maze[nextPlace];
		
			if (!visited[nextPlace])
			{
				q.emplace(nextPlace, cnt + 1);
				visited[nextPlace] = true;
			}
		}	
	}
}
int main()
{
	cin >> ladder >> snake;

	for (int i_cnt = 0; i_cnt < ladder + snake; ++i_cnt)
	{
		int first, last;
		cin >> first >> last;
		maze[first] = last;
	}
	
	bfs();

	
	return 0;
}