#include <iostream>
#include <array>
#include <algorithm>
#include <string>
using namespace std;
array<bool, 11> broken;

bool check(int a)
{
	string s = to_string(a);
	for (int i = 0; i < s.length(); ++i)
	{
		if (broken[s[i] - '0'])
			return false;
	}

	return true;
}
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a;
		cin >> a;
		// check 가 true 이면 고장난 버튼
		broken[a] = true;
	}

	int Min = abs(100 - n);

	for (int i = 0; i <= 1000000; ++i)
	{
		if (check(i))
		{
			string s = to_string(i);
			int len = s.length();
			Min = min(Min, len + abs(i - n));
		}
	}

	cout << Min;

	return 0;

}