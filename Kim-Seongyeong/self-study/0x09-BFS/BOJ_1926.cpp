#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[500][500];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

//≥–¿Ã π›»Ø
int bfs(int ix, int iy) {
	int cnt = 0;
	queue<pair<int, int>> q;

	q.push({ix, iy});
	board[ix][iy] = 0;

	while (!q.empty()) {
		cnt++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny]) {
				board[nx][ny] = 0;
				q.push({ nx, ny });
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int cnt = 0;
	int maxSize = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) {
				cnt++;
				maxSize = max(maxSize, bfs(i, j));
			}
		}
	}

	cout << cnt << '\n' << maxSize;

	return 0;
}