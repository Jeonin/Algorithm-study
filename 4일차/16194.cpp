#include <iostream>
#include <algorithm>
using namespace std;


int main(void)
{
	int n;
	cin >> n;
	int arr[10001];
	int dp[1001];

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	dp[1] = arr[1];


	for (int i = 2; i <= n; ++i)
	{
		dp[i] = arr[i];

		for (int j = 1; j < i; ++j)
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
	}

	cout << dp[n];
}