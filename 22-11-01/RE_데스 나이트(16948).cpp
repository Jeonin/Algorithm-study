#include <iostream>
#include <queue>

using namespace std;
int n;
pair<int, int> departure;
pair<int, int> destination;
bool visited[201][201];
int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };
int result = -1;

struct info
{
	int x, y, cnt;
};
void bfs()
{
	queue<info> q;
	q.push({ departure.first, departure.second , 0 });
	visited[departure.first][departure.second] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx == destination.first && ny == destination.second)
			{
				result = cnt + 1;
				return;
			}

			if(nx < 0 || ny< 0 || nx >= n || ny >= n || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			q.push({ nx, ny, cnt + 1 });
		}

	}
}

int main()
{
	cin >> n;

	cin >> departure.first;
	cin >> departure.second;

	cin >> destination.first;
	cin >> destination.second;

	bfs();

	cout << result;
	return 0;
}