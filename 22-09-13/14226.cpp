#include <iostream>
#include <queue>

#define MAX 2000
using namespace std;

int s;
bool visited[MAX][MAX];

struct info
{
	int x, y, time;
};

int bfs(void)
{
	queue<info> q;
	q.push({ 1, 0, 0 });
	visited[1][0] = true;

	while (!q.empty())
	{
		int screen = q.front().x;
		int clip = q.front().y;
		int cnt = q.front().time;

		if (screen == s)
			return cnt;
			

		if (screen > 0 && screen < MAX)
		{
			if (!visited[screen][screen])
			{
				visited[screen][screen] = true;
				q.push({ screen, screen , cnt + 1 });
			}

			if (!visited[screen -1 ][clip])
			{
				visited[screen][clip] = true;
				q.push({ screen, clip , cnt + 1 });
			}
		}

		if (clip > 0 && screen + clip < MAX)
		{
			if (!visited[screen + clip][clip])
			{
				visited[screen + clip][clip] = true;
				q.push({ screen + clip , clip , cnt + 1 });
			}
		}
	}
}


int main()
{
	cin >> s;

	int result = bfs();
	cout << result;

	return 0;
}