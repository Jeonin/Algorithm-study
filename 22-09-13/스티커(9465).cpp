#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int score[2][100'000];

void init(int num)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> score[i][j];
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		int dp[2][100'000];
		

		memset(&score, 0, sizeof(int) * 200000);
		cin >> n;
		init(n);

		for (int i = 0; i < n; ++i)
		{
			if (i == 0)
			{
				dp[0][i] = score[0][i];
				dp[1][i] = score[1][i];
			}
			else if (i == 1)
			{
				dp[0][i] = score[0][i] + dp[1][i - 1];
				dp[1][i] = score[1][i] + dp[0][i - 1];
			}
			else
			{
				dp[0][i] = score[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
				dp[1][i] = score[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
			}
			
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) <<'\n';
	}
	return 0;
}