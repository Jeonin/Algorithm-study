#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int n, k;


void bfs(int start)
{
	visited[start] = true;
	queue<pair<int, int>> q;
	q.push({ start, 0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == k)
		{
			cout << cnt;
			return;
		}

		if (x + 1 >= 0 && x + 1 <= 100000 && !visited[x + 1])
		{
			visited[x + 1] = true;
			q.push({ x + 1, cnt + 1 });
		}

		if (x - 1 >= 0 && x - 1 <= 100000 && !visited[x - 1])
		{
			visited[x - 1] = true;
			q.push({ x - 1, cnt + 1 });
		}

		if (x*2 >= 0 && x * 2 <= 100000 && !visited[x * 2])
		{
			visited[x * 2] = true;
			q.push({ x * 2, cnt + 1 });
		}
	}

	
	
}

int main()
{
	cin >> n >> k;
	bfs(n);
	return 0;
}