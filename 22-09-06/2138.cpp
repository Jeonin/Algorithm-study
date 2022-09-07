#include <iostream>
#include <string>
using namespace std;
int arr[100001];
int result[100001];
int main()
{
	int n;
	cin >> n;
	

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); ++i)
		arr[i] = str[i] - '0';

	cin >> str;

	for (int i = 0; i < n; ++i)
		result[i] = str[i] - '0';
	
	int cnt = 0;
	while (true)
	{
		int out = n;
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] != result[i])
			{
				arr[i] = 1 - arr[i];

				if (i > 0)
					arr[i - 1] = 1 - arr[i - 1];

				if (i < n - 1)
					arr[i + 1] = 1 - arr[i + 1];

				cnt++;
			}
			else
				out--;
		}

		if (out <= 0)
		{
			cout << cnt;
			break;
		}
	}

	return 0;
}