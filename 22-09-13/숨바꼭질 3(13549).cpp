#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
int n, k;
bool visited[100001];

void bfs()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.emplace(0, n);
	visited[n] = true;

	while (!q.empty())
	{
		int x = q.top().second;
		int time = q.top().first;
		q.pop();

		if (x == k)
		{
			cout << time << endl;
			return;
		}

		if (x * 2 < 100001 && !visited[x * 2])
		{
			q.emplace(time , x * 2);
			visited[x * 2] = true;
			
		}

		if (x +1 < 100001 && !visited[x+1])
		{
			q.emplace(time + 1, x + 1);
			visited[x + 1] = true;
			
		}

		if (x-1 >= 0 && !visited[x-1])
		{
			q.emplace(time + 1, x - 1);
			visited[x-1] = true;
			
		}		
	}
}

int main()
{
	cin >> n >> k;
	bfs();

	return 0;
}