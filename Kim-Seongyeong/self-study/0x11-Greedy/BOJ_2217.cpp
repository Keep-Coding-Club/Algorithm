#include <bits/stdc++.h>
using namespace std;

int n;
int roof[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> roof[i];
	}

	sort(roof, roof + n);

	int result = 0;
	//���� ����(i)�� �����ؼ� �ִ� �߷��� ����
	//roof[n-i]�� i�� ������ �� �ִ� �߷��� �Ǳ� ���� ���õ� ���� �� ���� ���� �߷�
	for (int i = 1; i <= n; i++)
		result = max(result, roof[n - i] * i);

	cout << result;
}