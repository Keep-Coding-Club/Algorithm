#include <iostream>
#include <queue>
using namespace std;

int M, N;
int map[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int inputX, int inputY) {
	queue<pair<int, int>> q;

	q.push({ inputX, inputY });
	map[inputX][inputY] = 0;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			if (map[nx][ny]) {
				q.push({ nx, ny });
				map[nx][ny] = 0;
			}
		}
	}
}

int main() {
	int t, x, y, k;

	cin >> t;

	while (t--) {
		int bug = 0;

		cin >> M >> N >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j]) {
					bfs(i, j);
					bug++;
				}
			}
		}

		cout << bug << '\n';
	}
}