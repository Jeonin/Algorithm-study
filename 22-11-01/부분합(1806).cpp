#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)	// �迭 �Է�
		cin >> arr[i];

	int start = 0, end = 0, sum = 0, minLen = 0x7FFFFFF;

	while (start <= end) 
	{
		if (sum >= s) {	// ���� �������� ���� s���� ũ�ų� ������ start ++
			minLen = min(minLen, end - start);	// ���� ª�� ���̸� ����
			sum -= arr[start++];
		}
		else if (end == n) break;
		else sum += arr[end++];	// end++ �����ν� sum ����
	}

	if (minLen == 0x7FFFFFF) cout << 0 << endl;	// �Ұ��� �ϸ� 0 ���
	else cout << minLen << endl;

	return 0;
}
