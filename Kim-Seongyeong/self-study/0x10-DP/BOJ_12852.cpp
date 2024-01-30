#include <bits/stdc++.h>
using namespace std;

//dp[i] : i���� 1�� �� �� �ִ� �ּڰ�
int dp[1000001];
//���Ḯ��Ʈ ���� ����(���� ���� ��θ� ����ϱ� ����)
//pre[i]�� ������ ��� �°��� ���� ����
int pre[1000001]; 
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			pre[i] = i / 3;
		}
	}

	cout << dp[n] << '\n';
	int cur = n;
	while (true) {
		cout << cur << ' ';
		if (cur == 1)break;
		cur = pre[cur];
	}

	return 0;
}