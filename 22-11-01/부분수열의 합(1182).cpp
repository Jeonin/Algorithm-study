#include <iostream>
#include <array>
#define MAX 21
using namespace std;
int n, s;
int sum, cnt;
array<int, MAX> progression;

void dfs(int num, int sum)
{
	if (num == n)
		return;

	if (sum + progression[num] == s)
		cnt++;
		
	dfs(num + 1, sum);
	dfs(num + 1, sum + progression[num]);

}
int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> progression[i];

	dfs(0, 0);

	cout << cnt;
	return 0;
}