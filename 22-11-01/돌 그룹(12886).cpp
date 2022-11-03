#include <iostream>
#include <queue>
#include <array>
#define MAX 1501
using namespace std;
int a, b, c, sum;
array<array<bool, MAX>, MAX> visited;

void bfs(int starta, int startb)
{
	queue<pair<int, int>> q;
	q.emplace(starta, startb);
	visited[starta][startb] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		array<int, 3> stone{ x, y, sum - (x + y) };

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (stone[i] < stone[j])
				{
					int nx = stone[i] * 2;
					int ny = stone[j] - stone[i];

					if(visited[nx][ny]) continue;
					
					visited[nx][ny] = true;
					q.emplace(nx, ny);
				}
			}
		}
	}
}
int main()
{

	cin >> a >> b >> c;
	sum = a + b + c;

	if (sum % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	
	bfs(a, b);
	cout << visited[sum / 3][sum / 3];
	return 0;
}