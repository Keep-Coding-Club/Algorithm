#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[100][100];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;

		for (int j = 0; j < M; j++) {
			board[i][j] = input[j] - '0';
		}
	}
	
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	board[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny]==1) {
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	cout << board[N-1][M-1];

	return 0;
}