#include <iostream>
#include <vector>
#include <array>
#define MAX 100'001
using namespace std;

int n;
array<int, MAX> arr;
vector<int> v[MAX];
bool visited[MAX];

void dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < v[start].size(); ++i)
	{
		int nextNode = v[start][i];

		if (!visited[nextNode])
		{
			arr[nextNode] = start;
			dfs(nextNode);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int nodeA, nodeB;
		cin >> nodeA >> nodeB;
		v[nodeA].emplace_back(nodeB);
		v[nodeB].emplace_back(nodeA);
	}

	dfs(1);

	for (int i = 2; i <= n; ++i)
		cout << arr[i] << '\n';

	return 0;

	//git test second
}