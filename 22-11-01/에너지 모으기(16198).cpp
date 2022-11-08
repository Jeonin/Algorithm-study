#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> beadWeight;
int MaxEnergy;

void dfs(int result)
{
	if (beadWeight.size() == 2)
	{
		MaxEnergy = max(MaxEnergy, result);
		return;
	}

	for (int i = 1; i < beadWeight.size() -1; ++i)
	{	
		int sum = beadWeight[i - 1] * beadWeight[i + 1];
		int tmp = beadWeight[i];

		beadWeight.erase(beadWeight.begin() + i);
		dfs(result + sum);
		beadWeight.insert(beadWeight.begin() + i, tmp);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int weight;
		cin >> weight;
		beadWeight.push_back(weight);
	}

	dfs(0);
	cout << MaxEnergy;
	return 0;
}