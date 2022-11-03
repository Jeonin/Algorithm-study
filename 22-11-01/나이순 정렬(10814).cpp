#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, string>> vecMemberInfo;
	for (int i = 0; i < n; ++i)
	{
		int member_age;
		string member_name;

		cin >> member_age >> member_name;
		vecMemberInfo.push_back({ member_age,  member_name });
	}

	stable_sort(vecMemberInfo.begin(), vecMemberInfo.end(), [](pair<int, string> a, pair<int, string> b)
	{
		if (a.first< b.first) return true;
		else return false;
	});

	for (auto it : vecMemberInfo)
		cout << it.first << " " << it.second <<'\n';

	return 0;
}