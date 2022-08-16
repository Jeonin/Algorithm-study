#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	int dp[1000001];

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int Min;

	for (int i = 4; i <= num; ++i)
	{
		int a = INT_MAX;
		int b = INT_MAX;
		int c = INT_MAX;

		if (i % 3 == 0)
			a = dp[i / 3] + 1;

		if (i % 2 == 0)
			b = dp[i / 2] + 1;

		c = dp[i - 1] + 1;

		Min = min({ a, b, c });

		dp[i] = Min;
	}

	cout << dp[num];

	return 0;

}