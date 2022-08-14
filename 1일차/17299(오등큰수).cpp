#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int arr[1000001];

int main()
{


	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> vcpy(n);

	stack<int> s;


	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		arr[v[i]]++;
	}

	s.push(0);

	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() && arr[v[s.top()]] < arr[v[i]])
		{
			vcpy[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty())
	{
		vcpy[s.top()] = -1;
		s.pop();
	}

	for (auto iter : vcpy)
		cout << iter << " ";

	return 0;
}