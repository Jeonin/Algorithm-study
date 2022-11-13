#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int landSize, treeNum, years;
int Energy[11][11];
int Insert_Energy[11][11];
vector<int> MAP[11][11];

int dx[8] = { 1, -1 , 1, -1, 1 ,-1, 0, 0 };
int dy[8] = { 0, 0, 1 , 1, -1, -1, 1, -1 };

void SpringAndSummer()
{
	for (int i = 0; i < landSize; ++i)
	{
		for (int j = 0; j < landSize; ++j)
		{
			if (MAP[i][j].size() == 0) continue;

			//나이만큼 양분을 먹는데 나이가 어린 순서대로 먹는다.
			int SumDiedTreesOld = 0;	
			vector<int> Temp;

			//봄
			sort(MAP[i][j].begin(), MAP[i][j].end());
			for (int k = 0; k < MAP[i][j].size(); ++k)
			{

				int Age = MAP[i][j][k];

				if (Energy[i][j] >= Age)
				{
					Energy[i][j] = Energy[i][j] - Age;
					Temp.push_back(Age + 1);
				}
				else
				{
					SumDiedTreesOld += Age / 2;
				}
			}

			MAP[i][j].clear();

			for (int k = 0; k < Temp.size(); ++k)
			{
				MAP[i][j].push_back(Temp[k]);
			}
			Energy[i][j] += SumDiedTreesOld;
		}
	}
}

void Fall()
{
	for (int i = 0; i < landSize; i++)
	{
		for (int j = 0; j < landSize; j++)
		{
			if (MAP[i][j].size() == 0) continue;

			for (int k = 0; k < MAP[i][j].size(); k++)
			{
				int Age = MAP[i][j][k];

				if (Age % 5 == 0)
				{
					for (int a = 0; a < 8; a++)
					{
						int nx = i + dx[a];
						int ny = j + dy[a];

						if (nx >= 1 && ny >= 1 && nx <= landSize && ny <= landSize)
						{
							MAP[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 0; i < landSize; ++i)
	{
		for (int j = 0; j < landSize; ++j)
		{
			Energy[i][j] += Insert_Energy[i][j];
		}
	}
}

int main()
{
	cin >> landSize >> treeNum >> years;

	for (int i = 0; i < landSize; ++i)
	{
		for (int j = 0; j < landSize; ++j)
		{
			cin >> Insert_Energy[i][j];
			Energy[i][j] =5;
		}
	}

	for (int i = 0; i < treeNum; ++i)
	{
		int x, y, old;
		cin >> x >> y >> old;
		MAP[x][y].emplace_back(old);
	}


	for (int i = 0; i < years; ++i)
	{
		SpringAndSummer();
		Fall();
		Winter();
	}

	int answer = 0;
	for (int i = 0; i < landSize; ++i)
	{
		for (int j = 0; j < landSize; ++j)
		{
			answer += MAP[i][j].size();
		}
	}

	cout << answer << endl;

	return 0;
}