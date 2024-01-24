/*
1. ���̺� �����ϱ�
-> DP[i][j] = ������� j���� ����� �����ؼ� ��� 
			i��° ��ܱ��� �ö��� �� ���� ���� �ִ�
			��, i��° ����� �ݵ�� ��ƾ� ��

			j�� 1 or 2 ��

2. ��ȭ�� ã��
-> DP[k][1] = max(DP[k-2][1], DP[k-2][2]) + Score[k]
	������� 1���� ����� �����ؼ� ��� k��° ��ܱ��� �ö��� �� ���� ���� �ִ�
	(������� 1���� ����� �����ؼ� ��Ҵٴ� ���� k-1��° ����� ���� �ʾ���, k-2�� ��ƾ� ��)

-> DP[k][2] = DP[k-1][1] + Score[k]
	������� 2���� ����� �����ؼ� ��� k��° ��ܱ��� �ö��� �� ���� ���� �ִ�
	('1���� ����� �����ؼ� ����' k-1��° ����� ����)

3. �ʱⰪ �����ϱ�
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

	//�ʱⰪ ����
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