#include <iostream>
#include <vector>	
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> result;
	result.reserve(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int sum = 0;
	for (auto i : v)
	{
		sum += i;
		result.push_back(sum);
	}

	int tatalsum = 0;
	for (auto i : result)
		tatalsum += i;

	cout << tatalsum;
	return 0;
}