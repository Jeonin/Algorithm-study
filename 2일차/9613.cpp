#include <iostream>
using namespace std;

int gcd(int a, int b)
{

	if (a % b != 0)
	{
		return gcd(b, a % b);
	}
	else
		return b;
}

int main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		int num;
		unsigned long long sum = 0;
		int arr[101];
		cin >> num;

		for (int i = 0; i < num; ++i)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < num; ++i)
		{
			for (int j = i + 1; j < num; ++j)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}