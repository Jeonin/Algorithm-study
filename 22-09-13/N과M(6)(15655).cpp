#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX];
bool visited[MAX];
vector<int> v;

void dfs(int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";

		cout << '\n';
		return;
	}

	for (size_t i = num; i < v.size(); ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = v[i];
			dfs(i +1, cnt + 1);
			visited[i] = false;
		}
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

	dfs(0, 0);
	return 0;
}