/*
1. 테이블 정의하기
dp[i][0] = i번째집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
dp[i][1] = i번째집까지 칠할 때 비용의 최솟값, 단 i번째 집은 초록
dp[i][2] = i번째집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑


2. 점화식 찾기
dp[k][0] = min(dp[k-1][1], dp[k-1][2]) + R[k]
dp[k][1] = min(dp[k-1][0], dp[k-1][2]) + G[k]
dp[k][2] = min(dp[k-1][0], dp[k-1][1]) + B[k]

3. 초기값 정하기
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

	//초기값 설정
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