#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ b, a });
	}

	sort(v.begin(), v.end());

	int cnt = 1;
	int end = v[0].first;

	
	for (int i = 1; i < v.size(); ++i)
	{
		if (end  <= v[i].second)
		{
			end = v[i].first;
			cnt++;
		}

	}

	cout << cnt;

	return 0;
}

