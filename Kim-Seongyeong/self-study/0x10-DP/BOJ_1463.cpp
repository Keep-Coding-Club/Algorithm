/*
1. 테이블 정의하기
-> DP[i] = i를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값

2. 점화식 찾기
-> DP[12] = ? 
12에서 할 수 있는 연산
	1. 3으로 나누거나 (DP[12] = DP[4] + 1)
	2. 2로 나누거나 (DP[12] = DP[6] + 1)
	3. 1을 빼거나 (DP[12] = DP[11]+1)

따라서, DP[12] = min(DP[4] + 1, DP[6] + 1, DP[11] + 1)

-> DP[k] = ?
	1. 3으로 나눠지면 3으로 나누거나 (DP[k] = DP[k/3] + 1)
	2. 2로 나눠지면 2로 나누거나 (DP[k] = DP[k/2] + 1)
	3. 1을 빼거나 (DP[k] = DP[k - 1] + 1)
1-3 중 최솟값

3. 초기값 정의하기
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