#include <iostream>
#include <vector>
#define MAX	3001
using namespace std;
int n;
int node[MAX][MAX];
bool visited[MAX];
int startNode;
vector<int> cycleNode;
bool IsFind;

void dfs(int start,int cnt)
{
	visited[start] = true;
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i] == false)
		{
			dfs(i, cnt+1);
		}


		if (cnt >= 2 && node[start][startNode] >= 1 && IsFind == false)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (visited[j] == true);
				cycleNode.emplace_back(j);
				
			}
			IsFind = true;
			return;
		}
	}
	visited[start] = false;

}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		//�̰� �߸��Ƴ�... vector���ؼ� �ι�° �迭�� ����� ������ �־��ְ� ���� ����� ���� �־������.
		node[a][b]++;
		node[b][a]++;
	}

	//1. ��ȯ���� ���ϴ� ������ ã�Ƴ�
	
	startNode = i;
	dfs(i, 0);

	
	//2. �� ������ ��ȯ�������� �Ÿ��� ã�Ƴ�



	return 0;
}