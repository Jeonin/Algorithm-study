#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	int n, k;
	cin >> n >> k;

	string str = " ";

	for (int i = 1; i <= n; ++i)
	{
		str += to_string(i);
	}

	int cnt = 0;
	for (auto ch : str)
	{
		if(cnt == k)
			cout<<ch;
		cnt++;
	}

	return 0;
}