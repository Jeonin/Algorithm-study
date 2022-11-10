#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	//»ê¼úÆò±Õ
	long long sum = 0;
	for (auto it : v)
		sum += it;

	cout << sum / n<< '\n';

	//Áß¾Ó°ª
	sort(v.begin(), v.end());
	int center = v.size() * 0.5;
	cout << v[center] << '\n';

	//ÃÖºó°ª
	array<int, 8000> arr{ 0 };
	vector<int> vcopy(v);
	int Max = 0;
	for (auto& it : vcopy)
	{
		it += 4000;
		Max = max(Max, ++arr[it]);
	}

	vector<int> freq;
	for (auto it : vcopy)
	{
		if (Max == arr[it])
			freq.push_back(it - 4000);
	}

	sort(freq.begin(), freq.end());
	freq.size() >= 2 ? cout << freq[1] : cout << freq[0];
	cout << '\n';

	//¹üÀ§
	cout << v.back() - v.front() << '\n';
	
		
	

	return 0;
}