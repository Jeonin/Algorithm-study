#include <iostream>
using namespace std;

void hanoi(int num, int from, int by, int to) 
{
	if (num == 1)
		cout << from <<' '<< to <<'\n';
	else
	{
		hanoi(num - 1, from, to, by);
		cout << from <<' '<< to << '\n';
		hanoi(num - 1, by, from, to);
	}
}

int main()
{
	int n;
	cin >> n;

	cout << (1 << n) - 1<< '\n';
	hanoi(n, 1, 2, 3);
	return 0;
}
