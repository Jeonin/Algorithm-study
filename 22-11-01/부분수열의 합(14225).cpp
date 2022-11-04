#include <iostream>
#include <array>
using namespace std;
int n;
array<int, 21> progression;
array<bool, 10'000'000> arrSum;

void dfs(int num, int sum)
{
	arrSum[sum] = true;

	if (num == n)
		return;
		
	dfs(num + 1, sum);
	dfs(num + 1, sum + progression[num]);
	
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> progression[i];


	dfs(0, 0);
	
	for (int i = 0; i < 10'000'000; ++i)
	{
		if (!arrSum[i])
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}