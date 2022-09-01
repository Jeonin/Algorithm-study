#include <iostream>
#define MAX	100001
using namespace std;

int Index[MAX];
int Inorder[MAX];
int Postorder[MAX];
int n;

void Preorder(int InStart, int InEnd, int PostStart, int PostEnd)
{
	if (InStart > InEnd || PostStart > PostEnd)
		return;

	int RootIndex = Index[Postorder[PostEnd]];
	int LeftSize = RootIndex - InStart;

	cout << Inorder[RootIndex] << ' ';
	Preorder(InStart, RootIndex - 1, PostStart, PostStart + LeftSize - 1);
	Preorder(RootIndex + 1, InEnd, PostStart + LeftSize, PostEnd - 1);


}
int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> Inorder[i];
		Index[Inorder[i]] = i;
	}

	for (int i = 1; i <= n; ++i)
		cin >> Postorder[i];

	Preorder(1, n, 1, n);
	return 0;
}

