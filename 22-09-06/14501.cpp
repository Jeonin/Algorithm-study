#include <iostream>
#include <algorithm>
using namespace std;
int t[16];
int p[16];
int dp[16];

int main()
{
	int n;
	cin >> n;


	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i] >> p[i];

		for (int j = 0; j < i; ++j)
		{
			if (j + t[j] <= i && t[i] + i <= n + 1 )
			{				
				dp[i] = max(dp[i], dp[j] + p[i]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		answer = max(answer, dp[i]);
	}

	cout << answer;
	return 0;

}