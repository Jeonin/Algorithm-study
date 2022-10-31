#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	int amount[10'001];
	long long dp[10'001];
	for (int i = 1; i <= n; ++i)
		cin >> amount[i];
	
	dp[0] = 0;
	dp[1] = amount[1];
	dp[2] = amount[1] + amount[2];
	
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = max({ dp[i - 1], dp[i - 2] + amount[i], dp[i-3] +amount[i] + amount[i-1] });
	}

	cout << dp[n];
	return 0;
}