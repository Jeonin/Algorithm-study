#include <iostream>
using namespace std;
int n;
int arr[16];
int result;

bool check(int level)
{
	for (int i = 0; i < level; i++)
		if (arr[i] == arr[level] || abs(arr[level] - arr[i]) == level - i)
			return false;
	
	return true;

}
void dfs(int cnt)
{
	if (cnt == n)
		result++;
	else
	{
		for (int i = 0; i < n; ++i)
		{
		
			arr[cnt] = i;
			if (check(cnt))
				dfs(cnt + 1);

		}
	}

}

int main()
{
	cin >> n;

	dfs(0);

	cout << result;

	return 0;
}