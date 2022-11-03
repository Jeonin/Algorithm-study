#include <iostream>
#include <array>

#define LOTTO 6
using namespace std;
int k;
array<int, 13> numbers;
array<int, 6> arr;

void dfs(int num, int cnt)
{
	if (cnt == LOTTO)
	{
		for (int i = 0; i < LOTTO; ++i)
			cout << arr[i] << " ";

		cout << '\n';
		return;
	}

	for (int i = num; i < k; ++i)
	{	
		arr[cnt] = numbers[i];
		dfs(i + 1, cnt + 1);
	}
}
int main()
{
	while (true)
	{	
		cin >> k;
		if (k == 0)	break;

		for (int i = 0; i < k; ++i)
			cin >> numbers[i];

		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}