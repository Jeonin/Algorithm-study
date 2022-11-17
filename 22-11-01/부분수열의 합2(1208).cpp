#include <iostream>
#include <array>
#include <unordered_map>
#define MAX 41
using namespace std;
int n, s;
array<int, MAX> element;
unordered_map<int, int> subsum;
unsigned long long cnt;

void rightseq(int mid, int sum)
{
	if (mid == n) {
		subsum[sum]++;
		return;
	}

	rightseq(mid + 1, sum);
	rightseq(mid + 1, sum + element[mid]);
}

void Leftseq(int start, int sum)
{
	if (start == n / 2) {
		cnt += subsum[s - sum];
		return;
	}

	Leftseq(start+1, sum);
	Leftseq(start+1, sum + element[start]);
}

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
	{
		cin >> element[i];
	}

	rightseq(n / 2, 0);
	Leftseq(0, 0);

	if (s == 0)
		cout << cnt - 1;
	else
		cout << cnt;

	return 0;
}