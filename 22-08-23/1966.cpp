#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		queue<pair<int, int>> q;
		priority_queue<int> importance;
		
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		int find = 0;

		for (int i = 0; i < n; ++i)
		{
			int value;
			cin >> value;
			q.emplace(i, value);
			importance.push(value);
		}

		while (!q.empty())
		{
			int index = q.front().first;
			int import = q.front().second;

			if (importance.top() > import)
			{
				q.push(q.front());
				q.pop();
			}
			else
			{
				cnt++;
				q.pop();
				importance.pop();

				if (index == m)
				{
					cout << cnt << '\n';
					break;
				}
			}
		}
		
		
	}

	return 0;
} 