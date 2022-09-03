#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;
vector<char> res;

bool check()
{
	int mo = 0;
	int ja = 0;

	for (int i = 0; i < L; ++i)
	{
		if (res[i] == 'a' ||
			res[i] == 'e' ||
			res[i] == 'i' ||
			res[i] == 'o' ||
			res[i] == 'u')
		{
			mo++;
		}
		else
			ja++;
	}

	return ja >= 2 && mo >= 1;
}

void dfs(int a)
{
	if ((int)res.size() == L)
	{
		if (check())
		{
			for (int i = 0; i < L; ++i)
				cout << res[i];
		}

		cout << '\n';
	}

	for (int i = a; i < C; ++i)
	{
		res.push_back(v[i]);
		dfs(i + 1);
		res.pop_back();
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; ++i)
	{
		char ch;
		cin >> ch;
		v.push_back(ch);
	}

	sort(v.begin(), v.end());

	dfs(0);

	return 0;
}
