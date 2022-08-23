#include <iostream>
#include <list>
using namespace std;


int main(void)
{
	int n;
	cin >> n;
	list<int> ls;

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		ls.push_back(a);
	}

	ls.sort();

	for (auto iter : ls)
		cout << iter << '\n';

	return 0;
}