#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];
vector<int> v;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";

		cout << '\n';
		return;
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		arr[cnt] = v[i];
		dfs(cnt + 1);
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	dfs(0);

	return 0;
}