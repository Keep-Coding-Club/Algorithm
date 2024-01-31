/*
11047�� ������ ����� ��� -> �׸��� ���
https://www.acmicpc.net/problem/11047

2294�� ������ ��� X ��� -> DP ���
https://www.acmicpc.net/problem/2294
*/

/*
������ Ǯ��
https://coco-ball.tistory.com/20
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	
	int coin[101];
	int dp[10001]; //���� �ݾ��� �� �ּ� ���� ����

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	//dp �ּڰ����� �����ؾ� �ϹǷ� �ִ����� �ʱ�ȭ
	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];

	return 0;
}