#include <iostream>
#include <array>
#include <climits>
using namespace std;
int n;
array<int, 1001> maze;
array<int, 1001> dp;


int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> maze[i];
		dp[i] = INT_MAX;
	}

	dp[1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= maze[i]; ++j) 
		{
			if (i + j <= n)
			{
				dp[i + j] = min(dp[i] + 1, dp[i + j]);
			}
		}
	}

	if (dp[n] == INT_MAX)
		cout << -1;
	else
		cout << dp[n];

	
	return 0;
}