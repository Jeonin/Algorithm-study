#include <iostream>
#include <vector>
#define Size 9
using namespace std;
int board[Size][Size];
vector<pair<int, int>> blanckSpace;
int cnt;
bool Isfinished;

bool Check(pair<int, int> blankPos)
{
	//구역을 나눠줌
	int divide_x = blankPos.first / 3;
	int divdie_y = blankPos.second / 3;

	//가로, 세로에 같은 숫자가 있는지 확인

	int col = blankPos.first;
	int row = blankPos.second;

	for (int i = 0; i < Size; ++i)
	{	
		if (board[col][row] == board[col][i] && i != row)
			return false;
		if (board[col][row] == board[i][row] && i != col)
			return false;
	}

	//나눈 사각형 안에 같은 숫자가 있는지 확인
	for (int i = divide_x * 3; i < divide_x * 3 + 3; ++i)
	{
		for (int j = divdie_y * 3; j < divdie_y * 3 + 3; ++j)
		{
			if (board[i][j] == board[col][row] && i != col && j != row)
				return false;
		}
	}

	//모든 역경을 이겨냈다면
	return true;

}

void sudoku(int num)
{
	if (num == cnt)
	{
		for (int i = 0; i < Size; ++i)
		{
			for (int j= 0; j < Size; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}

		Isfinished = true;
		return;
	}

	int col = blanckSpace[num].first;
	int row = blanckSpace[num].second;

	for (int i = 1; i <= Size; ++i)
	{
		
		board[col][row] = i; // 1~9 사이 숫자를 넣음

		if (Check(blanckSpace[num]))
			sudoku(num + 1);

		if (Isfinished)
			return;
	}

	board[col][row] = 0; // 둘다 아니라면 원상복구
	return;
}
int main()
{
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 0)
			{
				cnt++;
				blanckSpace.emplace_back(i, j);
			}
		}
	}

	sudoku(0);

	return 0;
}