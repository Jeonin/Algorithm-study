#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int sum = 0;
	int cnt = 0;
	
	for (int i = n-1; i >= 0; --i)
	{
	
		if (k == sum)
			break;

		while (v[i] <= k - sum)
		{
			sum += v[i];
			cnt++;	
		}

	}
	    
	cout << cnt;
	return 0;
}