#include <iostream>
#include <string>
using namespace std;
int map[51][51];
int diff[51][51];
int n, m;
int cnt;

int main()
{
	
	cin >> n >> m;
	string str[51];

	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
	}

	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int a = str[i][j] - '0';
			map[i][j] = a;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int a = str[i][j] - '0';
			diff[i][j] = a;
		}
	}



	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = 0; j < m - 2; ++j)
		{
			if (map[i][j] != diff[i][j])
			{
				for (int x = i; x < i + 3; ++x)
				{
					for (int y = j; y < j + 3; ++y)
					{
						map[x][y] = 1 - map[x][y];
					}
				}
				cnt++;
			}

		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] != diff[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt;

	return 0;
	
}