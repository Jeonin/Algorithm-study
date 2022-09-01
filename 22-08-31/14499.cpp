#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void check_bfs(vector<vector<int>>& v)
{
	queue<pair<int, int>> q;
	
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 2)
				q.emplace(i, j);
		}
	}



	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < v.size() && ny >= 0 && ny < v[x].size() && v[nx][ny] == 0)
			{
				q.emplace(nx, ny);
				v[nx][ny] = 2;

			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 0)
				cnt++;
		}
	}

	answer = max(answer, cnt);
}

void dfs(vector<vector<int>> v, int x, int y, int cnt)
{
	v[x][y] = 1;

	if (cnt == 0)
	{
		check_bfs(v);
		return;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 0)
				dfs(v, i, j, cnt - 1);
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 0)
			{
				dfs(v, i, j, 2);
			}
		}
	}


	cout << answer;

	return 0;

}