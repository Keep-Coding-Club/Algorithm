/*
BFS 시작점이 여러 개일 때
-> 모든 시작점을 queue에 넣으면 됨
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1000][1000];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny] == -1)
				continue;
			if (board[nx][ny] == 0) {
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				cout << -1;
				return 0;
			}
			result = max(result, board[i][j]);
		}
	}
	
	cout << result - 1;

	return 0;
}