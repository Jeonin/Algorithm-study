#include <iostream>
#include <array>
using namespace std;
int n, m;
int ans = 0;
array<int, 10'001> sequence;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = i; j < n; ++j)
		{
			sum += sequence[j];

			if (sum == m)
			{
				ans++;
				break;
			}
		}
	}

	cout << ans;
	return 0;
}