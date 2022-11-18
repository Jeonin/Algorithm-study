#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

unsigned int t;
int n, m;
array<int, MAX> arrA;
array<int, MAX> arrB;
vector<int> a;
vector<int> b;

int main()
{
	cin >> t;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arrA[i];
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> arrB[i];
	}

	
	for (int i = 0; i < n; ++i)
	{
		int sumA = arrA[i];
		a.emplace_back(sumA);

		for (int j = i + 1; j < n; ++j)
		{
			sumA += arrA[j];
			a.emplace_back(sumA);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int sumB = arrB[i];
		b.emplace_back(sumB);

		for (int j = i + 1; j < m; ++j)
		{
			sumB += arrB[j];
			b.emplace_back(sumB);
		}
	}

	sort(a.begin(), a.end());

	unsigned long long result = 0;
	for (auto iter : b)

	{
		int diff = t - iter;
		auto ub = upper_bound(a.begin(), a.end(), diff);
		auto lb = lower_bound(a.begin(), a.end(), diff);

		result += (ub - lb);
	}

	cout << result;

	return 0;
}