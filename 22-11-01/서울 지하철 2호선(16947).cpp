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

		//이게 잘못됐네... vector로해서 두번째 배열에 연결된 개수를 넣어주고 값에 연결된 곳을 넣어줘야함.
		node[a][b]++;
		node[b][a]++;
	}

	//1. 순환선에 속하는 노드들을 찾아냄
	
	startNode = i;
	dfs(i, 0);

	
	//2. 각 노드들의 순환선까지의 거리를 찾아냄



	return 0;
}