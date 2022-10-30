#include <iostream>	
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int n;
int arr[11][11];
bool visited[11];
int iMin = INT_MAX;
int start;

void dfs(int visit, int sum, int cnt)
{
	if (cnt == n)
	{
		if(arr[visit][start] > 0)
			iMin = min(iMin, sum + arr[visit][start]);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (arr[visit][i] == 0) continue;
		if (visited[i] == true) continue;

		visited[i] = true;
		dfs(i, sum + arr[visit][i], cnt + 1);
		visited[i] = false;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		start = i;
		visited[i] = true;
		dfs(i, 0, 1);
		visited[i] = false;
	}

	cout << iMin;

	return 0;
}