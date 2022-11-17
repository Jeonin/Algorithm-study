#include <iostream>
#include <vector>
#include <cmath>
#define MAX 4'000'001
using namespace std;
int n;
bool visited[MAX];

int main()
{
	cin >> n;
	static unsigned int result = 0;

	vector<int> cnt;

	for (int i = 2; i < sqrt(MAX);++i)
	{
		if(visited[i]) continue;

		cnt.emplace_back(i);

		for (int j = i+i; j < MAX; j += i)
		{
			visited[j] = true;
		}
	}

	static int first = 0;
	static int last = 0;
	static unsigned int sum = 0;
	while (true)
	{
		if (sum >= n)
		{
			sum -= cnt[first++];
		}
		else if (last == cnt.size())
			break;
		else
			sum += cnt[last++];
	
		if (sum == n) result++;
	}

	cout << result;


	return 0;
}