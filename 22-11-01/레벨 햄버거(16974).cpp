#include <iostream>
using namespace std;

int N;
long long X;
long long burger[51];//햄버거에 들어간 전체 재료의 수
long long patty[51];//햄버거에 들어간 전체 패티의 수

long long getPatty(int n, long long x) {

	if (n == 0) {//패티 한 장만 있음
		if (x == 1)
			return 1;
		else if (x == 0)
			return 0;
	}
	//마지막 장은 햄버거 번
	if (x == 1)
		return 0;

	//x가 (레벨n-1)B의 재료 개수보다 작거나 같을 때
	else if (x <= burger[n - 1] + 1)
		return getPatty(n - 1, x - 1);

	//x가 P(레벨n-1)B의 재료 개수와 같을 때
	else if (x == 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1;

	//x가 (레벨n-1)P(레벨n-1)B의 재료 개수보다 작거나 같을 때
	else if (x <= burger[n - 1] + 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1 + getPatty(n - 1, x - 1 - burger[n - 1] - 1);

	//x가 버거의 전체 재료 개수와 같을 때
	else
		return patty[n - 1] * 2 + 1;
}

int main() {
	cin >> N >> X;
	burger[0] = 1;
	patty[0] = 1;
	//i번째 햄버거의 전체 재료수와 패티수 각각 저장
	for (int i = 1; i <= N; i++) {
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1;
		patty[i] = patty[i - 1] + 1 + patty[i - 1];
	}
	cout << getPatty(N, X) << '\n';
	return 0;
}