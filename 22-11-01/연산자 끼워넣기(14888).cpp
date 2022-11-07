#include <iostream>
#include <array>
#include <algorithm>
#include <climits>
using namespace std;

enum {add, sub, mul, divide};

int n;
int iMax = INT_MIN, iMin = INT_MAX;
array<int, 12> numbers;
array<int, 4> mark;

void dfs(int result, int cnt)
{
	if (cnt == n)
	{
		iMax = max(iMax, result);
		iMin = min(iMin, result);
		return;a
	}

	for (int i = 0; i < 4; ++i)
	{
		if (mark[i] > 0)
		{
			mark[i]--;

			switch (i)
			{
			case add:
				dfs(result + numbers[cnt], cnt + 1);
				break;
			case sub:
				dfs(result - numbers[cnt], cnt + 1);
				break;
			case mul:
				dfs(result * numbers[cnt], cnt + 1);
				break;
			case divide:
				dfs(result / numbers[cnt], cnt + 1);
				break;
			}

			mark[i]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];
	
	for (int i = 0; i < 4; ++i)
		cin >> mark[i];

	dfs(numbers[0], 1);

	cout << iMax << '\n';
	cout << iMin << '\n';

	return 0;
}