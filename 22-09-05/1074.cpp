#include <iostream>
using namespace std;
int n, r, c;
int ans;

void Z(int col, int row, int size)
{
	if (col == r && row == c)
	{
		cout << ans << '\n';
		return;
	}

	if (r < col + size && r >= col && c < row + size && c >= row)
	{
		Z(col, row, size / 2);

		Z(col, row + size / 2, size / 2);

		Z(col + size / 2, row, size / 2);

		Z(col + size / 2, row + size / 2, size / 2);
	}

	else
		ans += size * size;

}


int main()
{
	cin >> n >> r >> c;

	Z(0, 0, (1 << n));

	return 0;

}