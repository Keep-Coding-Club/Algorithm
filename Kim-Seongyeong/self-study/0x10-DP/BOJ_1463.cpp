/*
1. ���̺� �����ϱ�
-> DP[i] = i�� 1�� ����� ���� �ʿ��� ���� ��� Ƚ���� �ּڰ�

2. ��ȭ�� ã��
-> DP[12] = ? 
12���� �� �� �ִ� ����
	1. 3���� �����ų� (DP[12] = DP[4] + 1)
	2. 2�� �����ų� (DP[12] = DP[6] + 1)
	3. 1�� ���ų� (DP[12] = DP[11]+1)

����, DP[12] = min(DP[4] + 1, DP[6] + 1, DP[11] + 1)

-> DP[k] = ?
	1. 3���� �������� 3���� �����ų� (DP[k] = DP[k/3] + 1)
	2. 2�� �������� 2�� �����ų� (DP[k] = DP[k/2] + 1)
	3. 1�� ���ų� (DP[k] = DP[k - 1] + 1)
1-3 �� �ּڰ�

3. �ʱⰪ �����ϱ�
DP[1] = 0
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	dp[1] = 0;

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N];

	return 0;
}