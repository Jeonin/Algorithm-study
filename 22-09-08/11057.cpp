#include <iostream>
#define MOD 10007
using namespace std;
int dp[1001][10];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 10; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; ++i)
	{
		result += dp[n][i];
	}

	cout << result % MOD;
	return 0;
}