#include <iostream>
using namespace std;

typedef unsigned long long ulong;

ulong factorial(ulong num)
{
	if (num == 1)
		return 1;

	return num * factorial(num - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	ulong a = factorial(n);

	ulong result = (factorial(n) / (factorial(m))) * (factorial(n) / factorial(n - m));
	cout<< result;
	return 0;
}

