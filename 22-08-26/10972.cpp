#include <iostream>
#include <vector>
using namespace std;

bool permutation(vector<int> &v, int num)
{
	int k = num - 1;
	while (k > 0 && v[k - 1] >= v[k])
	{
		--k;
	}

	if (k <= 0)
		return false;

	int j = num - 1;
	while (v[k - 1] >= v[j])
	{
		--j;
	}

	swap(v[k - 1], v[j]);

	j = num - 1;

	while (k < j)
	{
		swap(v[k], v[j]);
		k++;
		j--;
	}
	return true;
	
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	if (permutation(v, n))
	{
		for (int i = 0; i < n; ++i)
		{
			cout << v[i] << " ";
		}
	}
	else
		cout << -1;


	return 0;
}