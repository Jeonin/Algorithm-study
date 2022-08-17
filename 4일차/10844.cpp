#include <iostream>
#define MOD	1000000000
using namespace std;


int main()
{
	int t;
	cin >> t;

	
	long long dp[101][10]{};

	for (int i = 1; i <= 9; ++i)
	{
		dp[1][i] = 1;
	}

	
	for (int i = 2; i <= t; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			dp[i][j] = 0;

			if (j - 1 >= 0)
			{
				dp[i][j] += dp[i - 1][j - 1];
			}

			if (j + 1 <= 9)
			{
				dp[i][j] += dp[i - 1][j + 1];
			}

			dp[i][j] %= MOD;

		}
	}

	long long result = 0;

	for (int i = 0; i <= 9; ++i)
	{
		result += dp[t][i];
	}

	cout << result % MOD;
	return 0;
}