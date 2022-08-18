#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> v(9);
	int sum = 0;

	for (int i = 0; i < 9; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (100 == sum - (v[i] + v[j]))
			{
				v[i] = -1;
				v[j] = -1;

				sort(v.begin(), v.end());

				for (int i = 2; i < 9; ++i)
				{
					cout << v[i] << '\n';
				}

				return 0;
			}
		}
	}


	
}