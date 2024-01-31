/*
11047은 동전이 배수인 경우 -> 그리디 사용
https://www.acmicpc.net/problem/11047

2294는 동전이 배수 X 경우 -> DP 사용
https://www.acmicpc.net/problem/2294
*/

/*
참고한 풀이
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
	int dp[10001]; //현재 금액일 때 최소 동전 개수

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	//dp 최솟값으로 갱신해야 하므로 최댓값으로 초기화
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