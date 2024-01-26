/*
1. 테이블 정의하기
	dp[i] = 2*i 크기의 직사각형을 채우는 방법의 수

2. 점화식 찾기
	dp[n] = dp[n-1] + dp[n-2]

3. 초기값 정하기
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