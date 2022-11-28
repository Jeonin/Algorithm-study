#include <iostream>
using namespace std;

int N;
long long X;
long long burger[51];//�ܹ��ſ� �� ��ü ����� ��
long long patty[51];//�ܹ��ſ� �� ��ü ��Ƽ�� ��

long long getPatty(int n, long long x) {

	if (n == 0) {//��Ƽ �� �常 ����
		if (x == 1)
			return 1;
		else if (x == 0)
			return 0;
	}
	//������ ���� �ܹ��� ��
	if (x == 1)
		return 0;

	//x�� (����n-1)B�� ��� �������� �۰ų� ���� ��
	else if (x <= burger[n - 1] + 1)
		return getPatty(n - 1, x - 1);

	//x�� P(����n-1)B�� ��� ������ ���� ��
	else if (x == 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1;

	//x�� (����n-1)P(����n-1)B�� ��� �������� �۰ų� ���� ��
	else if (x <= burger[n - 1] + 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1 + getPatty(n - 1, x - 1 - burger[n - 1] - 1);

	//x�� ������ ��ü ��� ������ ���� ��
	else
		return patty[n - 1] * 2 + 1;
}

int main() {
	cin >> N >> X;
	burger[0] = 1;
	patty[0] = 1;
	//i��° �ܹ����� ��ü ������ ��Ƽ�� ���� ����
	for (int i = 1; i <= N; i++) {
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1;
		patty[i] = patty[i - 1] + 1 + patty[i - 1];
	}
	cout << getPatty(N, X) << '\n';
	return 0;
}