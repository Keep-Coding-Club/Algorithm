/*
1. ���̺� �����ϱ�
dp[i][0] = i��°������ ĥ�� �� ����� �ּڰ�, �� i��° ���� ����
dp[i][1] = i��°������ ĥ�� �� ����� �ּڰ�, �� i��° ���� �ʷ�
dp[i][2] = i��°������ ĥ�� �� ����� �ּڰ�, �� i��° ���� �Ķ�


2. ��ȭ�� ã��
dp[k][0] = min(dp[k-1][1], dp[k-1][2]) + R[k]
dp[k][1] = min(dp[k-1][0], dp[k-1][2]) + G[k]
dp[k][2] = min(dp[k-1][0], dp[k-1][1]) + B[k]

3. �ʱⰪ ���ϱ�
dp[1][0] = R[1]
dp[1][1] = G[1]
dp[1][2] = B[1]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int dp[1001][3];
	int r[1001], g[1001], b[1001];

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> r[i] >> g[i] >> b[i];

	//�ʱⰪ ����
	dp[1][0] = r[1];
	dp[1][1] = g[1];
	dp[1][2] = b[1];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
	}

	cout << *min_element(dp[N], dp[N] + 3);

	return 0;
}