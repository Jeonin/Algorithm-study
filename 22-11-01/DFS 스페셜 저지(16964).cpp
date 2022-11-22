#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#define MAX 100'001
using namespace std;
int n;
vector<int> graph[MAX];
array<int, MAX> result;
bool visited[MAX];

void dfs(int num)
{
	if (visited[num] == true)
		return;

	visited[num] = true;

	bool IsSame = true;
	for (int i = num; i < num + graph[num].size(); ++i)
	{
		if (visited[graph[num][i]]) continue;
		
		for (auto iter : graph[num])
		{
			if (result[iter] == i)
				dfs(i);
			else
			{
				cout << 0;
				exit(0);
			}
		}
	}

	visited[num] = false;
}
int main()
{	
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int first, second;
		cin >> first >> second;
		graph[first].emplace_back(second);
		graph[second].emplace_back(first);
	}

	for (int i = 0; i < n; ++i)
	{
		int ans;
		cin >> ans;
		result[ans] = i;
	}

	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [&](int a, int b)
		{
			return result[a] < result[b];
		});
	}

	if (graph[0].front() != 1)
	{
		cout << 0;
		return 0;
	}

	dfs(1);

	cout << 1;
	return 0;
}