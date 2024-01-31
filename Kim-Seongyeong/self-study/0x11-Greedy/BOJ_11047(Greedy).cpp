/*
Greedy �˰���
	= ���� ���� ������ ���� �ٽþ������� ���ϴ� �˰���
	= ������ ���� Ž�� ������ ���̴� �˰��� 
*/

/*
11047�� ������ ����� ��� -> �׸��� ���
https://www.acmicpc.net/problem/11047

2294�� ������ ��� X ��� -> DP ���
https://www.acmicpc.net/problem/2294
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	int coin[10];
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += k / coin[n - i - 1];
		k %= coin[n - i - 1];
	}

	cout << cnt;

	return 0;
}