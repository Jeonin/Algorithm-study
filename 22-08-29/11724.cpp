#include <iostream>
#define MAX 1001
using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX];

int dfs(int start)
{
	visited[start] = true;

	for (int i = 1; i <= n; ++i)
	{
		int y = map[start][i];

		if (y != 0 && !visited[i])
		{
			visited[i] = true;
			dfs(i);


		}
	}

	return 1;
}
int main()
{
	
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		if(!visited[i])
			cnt += dfs(i);
	}

	cout << cnt;
	return 0;
}