#include <iostream>
#include <algorithm>
#include <climits>
#define MOD	10007

using namespace std;

int main(void)
{
	int num;
	cin >> num;

	int dp[1001];

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;


	for (int i = 4; i <= num; ++i)
	{
		dp[i] = (dp[i - 2] * 2 + dp[i - 3]) % MOD;
	}

	cout << dp[num] % MOD;

	return 0;

}