#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ulong	unsigned long long
using namespace std;

int n, m;
int MAX = INT_MIN;

bool check(int _mid, vector<int> v)
{
	ulong sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = v[i] - _mid;

		if (a > 0)
			sum += a;
	}

	if (sum >= m)
		return true;

	else
		return false;

}

void bs(int start, int end, vector<int> _v)
{
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (check(mid, _v))
		{
			start = mid + 1;
		}
		else
			end = mid - 1;

		
	}

	MAX = end;
}
int main()
{
	
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	bs(0, v[v.size()-1], v);


	cout << MAX;

	return 0;
	
}