#include <iostream>
using namespace std;
int paper[2200][2200];
int result[3];

bool check(int row, int col, int vol)
{
	int check = paper[row][col];
	for (int i = row; i < row + vol; ++i)
	{
		for (int j = col; j < col + vol; ++j)
		{
			if (paper[i][j] != check)
				return false;
		}
	}

	return true;
}


void division(int row, int col, int vol)
{
	if (check(row, col, vol))
		result[paper[row][col]]++;
	else
	{
		int size = vol / 3;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				division(row + size * i, col + size * j, size);
			}
		}
	}

}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;
			paper[i][j] = a + 1;
		}
	}

	division(0, 0, n);

	cout << result[0] <<'\n' << result[1] << '\n' << result[2];

	return 0;
}