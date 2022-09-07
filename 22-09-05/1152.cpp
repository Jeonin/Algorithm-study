#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	string str;
	cin.ignore();
	getline(cin, str);
	str += '\0';

	int cnt = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ' || str[i] == '\0')
			cnt++;

	}

	cout << cnt;

	return 0;
}