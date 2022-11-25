#include <iostream>
#include <array>
using namespace std;
int n;
long long dp[101][21];

int main()
{
	cin >> n;
	array<int, 101> numbers;
	for (int i = 1; i <= n; ++i)
		cin >> numbers[i];

	int target = numbers[n];

	dp[1][numbers[1]] = 1;

	for (int i = 2; i <= n - 1; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			if(dp[i-1][j] == 0) continue;

			if (j + numbers[j] <= 20)
				dp[i][j + numbers[j]] += dp[i - 1][j];

			if (j - numbers[j] >= 0)
				dp[i][j - numbers[j]] += dp[i - 1][j];
		}
	}
	
	cout<<dp[n - 1][target];

	return 0;
}