#include <iostream>
#include <vector>
#include <array>
#include <queue>
#define MAX 100001
using namespace std;
int n;
vector<int> graph[MAX];
array<int, MAX> result;
bool visited[MAX];
int start;

bool compare(const vector<int>& ans)
{
	
	for (int i = start; i < start + ans.size(); ++i)
	{
		bool IsSame = false;

		for (int j = 0; j < ans.size(); ++j)
		{
			if (result[i] == ans[j])
				IsSame = true;
		}

		if (IsSame == false)
			return false;

	}

	start += ans.size() + 1;

	return true;
}

void bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = true;
	
	start = 1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		vector<int> temp;

		for (int i = 0; i < graph[x].size(); ++i)
		{
			int nx = graph[x][i];
			if (visited[nx] == false)
			{
				visited[nx] = true;
				temp.emplace_back(nx);		
			}
		}

		if (compare(temp) == false)
		{
			cout << 0;
			exit(0);
		}

	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int begin, end;
		cin >> begin >> end;
		graph[begin].emplace_back(end);
		graph[end].emplace_back(begin);
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> result[i];
	}

	if (result[0] != 1)
	{
		cout << 0;
		return 0;
	}

	bfs();

	cout << 1;
	return 0;
}