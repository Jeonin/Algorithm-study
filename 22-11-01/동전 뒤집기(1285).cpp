#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[21][21];

	memset(&arr, 0, sizeof(int) * n * n);

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); ++j)
		{
			if (str[j] == 'H')
				arr[i][j] = 1;
			else
				arr[i][j] = -1;
		}

	}

	while (true)
	{
		bool isbreak = true;

		for (int i = 0; i < n; ++i)
		{
			int sum = 0;
			for (int j = 0; j < n; ++j)
			{
				sum += arr[i][j];
			}
			
			if (sum < 0)
			{
				isbreak = false;
				for (int j = 0; j < n; ++j)
				{
					arr[i][j] *= -1;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			int sum = 0;
			for (int j = 0; j < n; ++j)
			{
				sum += arr[j][i];
			}

			if (sum < 0)
			{
				isbreak = false;
				for (int j = 0; j < n; ++j)
				{
					arr[j][i] *= -1;
				}
			}
		}

		if (isbreak)
			break;
	}


	int result = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] == -1)
				result++;
		}
	}
	cout << result;
	return 0;
}