#include <iostream>
using namespace std;
long long d[1000001][4];
const long long mod = 1000000009LL;
const int limit = 100000;


int main()
{
	for (int i = 1; i <= limit; i++)
	{
		if (i - 1 >= 0)
		{
			d[i][1] = d[i - 1][2] + d[i - 1][3];
			if (i == 1)
			{
				d[i][1] = 1;
			}
		}

		if (i - 2 >= 0)
		{
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			if (i == 2)
			{
				d[i][2] = 1;
			}
		}
		if (i - 3 >= 0)
		{
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			if (i == 3)
			{
				d[i][3] = 1;
			}
		}

		d[i][1] %= mod;
		d[i][2] %= mod;
		d[i][3] %= mod;

	}

	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;

		cout << (d[num][1] + d[num][2] + d[num][3]) % mod << '\n';


	}
	return 0;
}