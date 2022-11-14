#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int k;
char c[10];
bool visited[10];
vector<string> answer;

bool IsOk(string num)
{
	for (int i = 0; i < k; ++i)
	{
		if (c[i] == '>')
		{
			if (num[i] < num[i + 1])
				return false;
		}
		else
		{
			if (num[i] > num[i + 1])
				return false;
		}
	}

	return true;
}

void dfs(int index, string num)
{
	if (index == k + 1)
	{
		if (IsOk(num))
		{
			answer.emplace_back(num);
			
		}
		return;
	}


	for (int i = 0; i < 10; ++i)
	{
		if (visited[i]) continue;

		visited[i] = true;
		dfs(index + 1, num + to_string(i));
		visited[i] = false;
	}
}
int main()
{
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> c[i];
	}

	dfs(0, "");

	auto result = minmax_element(answer.begin(), answer.end());

	cout << *result.second << '\n';
	cout << *result.first;

	return 0;
}