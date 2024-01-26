/*
1. ���̺� �����ϱ�
	dp[i] = 2*i ũ���� ���簢���� ä��� ����� ��

2. ��ȭ�� ã��
	dp[n] = dp[n-1] + dp[n-2]

3. �ʱⰪ ���ϱ�
	dp[1] = 1
	dp[2] = 2
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[N];

	return 0;
}