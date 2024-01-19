#include <bits/stdc++.h>
using namespace std;

/*
* func �Լ��� ��� ������� ���������� ��� ������,
* �ͳ������� �����Ͽ�
* n�� 1�϶� �� ����, n�� k �� ����, k+1�� ���� �� ����
*/

void func(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	//n-1���� ������ ��� a���� ��� 6-a-b�� �ű��
	func(a, 6 - a - b, n - 1);
	//n�� ������ ��� a���� ��� b�� �ű��
	cout << a << ' ' << b << '\n';
	//n-1���� ������ ��� 6-a-b���� ��� b�� �ű��.
	func(6 - a - b, b, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k;
	cin >> k;

	//��Ʈ ���� : 1�� ��Ʈ �������� kĭ �о��
	cout << (1 << k) - 1 << '\n';

	//���� k���� 1�� ��տ��� 3�� ������� �ű�� ���
	func(1, 3, k);
}