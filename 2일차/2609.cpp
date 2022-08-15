#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	
	if (a % b != 0)
	{	
		return gcd(b, a % b);
	}
	else
		return b;
}

int main()
{
	int a, b;
	cin >> a >> b;

	int igcd = gcd(a, b);

	int lcm = a * b / igcd;

	cout << igcd << '\n' << lcm;

	return 0;
}