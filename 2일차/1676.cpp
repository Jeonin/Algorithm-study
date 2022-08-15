#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int five = 0, fifteenfive = 0 , onehundredfifteenfive = 0;

	five = n / 5;
	fifteenfive = n / 25;
	onehundredfifteenfive = n / 125;

	cout << five + fifteenfive + onehundredfifteenfive;
	return 0;
}