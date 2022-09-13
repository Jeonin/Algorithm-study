#include <iostream>
#include <algorithm>

using namespace std;
int state[21][21];
int n;
bool check[21];
int Min = INT_MAX;
void dfs(int x, int pos)
{

	if (x == n / 2)
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (check[i] == true && check[j] == true)
					start += state[i][j];

				if (check[i] == false && check[j] == false)
					link += state[i][j];
			}
		}

		int temp = abs(start - link);
		Min = min(Min, temp);

		return;
	}

	for (int i = pos; i < n; ++i)
	{
		check[i] = true;
		dfs(x + 1, i + 1);
		check[i] = false;
	}
}

int main()
{
	
	cin >> n;
	

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> state[i][j];
		}
	}

	dfs(0, 1);

	cout << Min;

	return 0;
}