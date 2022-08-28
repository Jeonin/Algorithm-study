#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int n, m, v;
int graph[1001][1001];
bool visited[1001];

void dfs(int start)
{
	visited[start] = true;
	cout << start << ' ';
	for (int i = 1; i <= n; ++i)
	{
		int y = start;

		if (graph[y][i] == 1 && !visited[i])
		{		
			visited[i] = true;
			dfs(i);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		cout << x << ' ';

		for (int i = 1; i <= n; ++i)
		{
			if (graph[x][i] == 1 && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}



int main(void)
{
	
	cin >> n >> m >> v;

	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(v);
	cout << '\n';
	memset(visited, 0, sizeof(visited));
	bfs(v);

	cout << sizeof(visited);

	return 0;
}