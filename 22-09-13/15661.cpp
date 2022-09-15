#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[21][21];
bool visited[21];
int Min = 1000;

void dfs(int x, int pos)
{
	if (n / 2 == x)
	{
		int start = 0, link = 0;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (visited[i] && visited[j])
					start += arr[i][j];

				if (!visited[i] && !visited[j])
					link += arr[i][j];
			}
		}

		Min = min(Min, abs(start - link));

		return;

		
	}

	for (int i = pos; i < n; ++i)
	{
		visited[i] = true;
		dfs(x + 1, i + 1);
		visited[i] = false;
	}
}


int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0, 1);

	cout << Min;

	return 0;
}