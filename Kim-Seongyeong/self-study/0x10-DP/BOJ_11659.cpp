/*
prefix sum(누적합) 문제

dp[i] = a[1] + a[2] + ... + a[i]
dp[i] = dp[i-1] + a[i]

a[i] + a[i+1] + ... + a[j]
= (a[1] + a[2] + ... + a[j]) - (a[1] + a[2] + ... + a[i-1])
= dp[j] - dp[i-1]
*/

#include <bits/stdc++.h>
using namespace std;

int num[100001];
long long dp[100001]; //i의  누적합

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	dp[0] = 0;

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		dp[i] = dp[i - 1] + num[i];
	}

	int i, j;
	while (M--) {
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}

	return 0;
}
