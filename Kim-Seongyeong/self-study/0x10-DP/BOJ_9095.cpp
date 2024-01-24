/*
1. ���̺� �����ϱ�
-> DP[i] = i�� 1,2,3�� ������ ��Ÿ���� ����� ��

2. ��ȭ�� ã��
-> DP[4] = ?
	1+1+1+1, 3+1, 2+1+1, 1+2+1 : (3�� 1,2,3�� ���� ��Ÿ���� ���) + 1, DP[3] 
	1+1+2, 2+2 : (2�� 1,2,3�� ������ ��Ÿ���� ���) + 2, DP[2]
	1+3 : (1�� 1,2,3�� ���� ��Ÿ���� ���) + 3, DP[1]

����, DP[4] = DP[1] + DP[2] + DP[3]
DP[i] = DP[i-1] + DP[i-2] + DP[i-3]

3. �ʱⰪ �����ϱ�
DP[1] = 1
DP[2] = 2
DP[3] = 4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, n;
	cin >> T;

	int dp[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];


	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}