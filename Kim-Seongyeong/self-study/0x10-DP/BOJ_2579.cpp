/*
1. 테이블 정의하기
-> DP[i][j] = 현재까지 j개의 계단을 연속해서 밟고 
			i번째 계단까지 올라섰을 때 점수 합의 최댓값
			단, i번째 계단은 반드시 밟아야 함

			j는 1 or 2 임

2. 점화식 찾기
-> DP[k][1] = max(DP[k-2][1], DP[k-2][2]) + Score[k]
	현재까지 1개의 계단을 연속해서 밟고 k번째 계단까지 올라섰을 때 점수 합의 최댓값
	(현재까지 1개의 계단을 연속해서 밟았다는 것을 k-1번째 계단을 밟지 않았음, k-2는 밟아야 함)

-> DP[k][2] = DP[k-1][1] + Score[k]
	현재까지 2개의 계단을 연속해서 밟고 k번째 계단까지 올라섰을 때 점수 합의 최댓값
	('1개의 계단을 연속해서 밟은' k-1번째 계단을 밟음)

3. 초기값 정의하기
DP[1][1] = Score[1], DP[1][2] = 0,
DP[2][1] = Scpre[2], DP[2][2] = Score[1] + Score[2]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int dp[301][2];
	int score[301];
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> score[i];

	//초기값 정의
	dp[1][1] = score[1];
	dp[1][2] = 0;
	dp[2][1] = score[2];
	dp[2][2] = score[1] + score[2];

	for (int i = 3; i <= N; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
		dp[i][2] = dp[i - 1][1] + score[i];
	}
	
	cout << max(dp[N][1], dp[N][2]);

	return 0;
}