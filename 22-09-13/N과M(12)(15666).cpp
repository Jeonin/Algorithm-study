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

	int temp = 0;

	for (int i = num; i < v.size(); ++i)
	{
		if (v[i] != temp)
		{		
			arr[cnt] = v[i];
			temp = arr[cnt];
			dfs(i, cnt + 1);		
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	dfs(0, 0);
	return 0;
}