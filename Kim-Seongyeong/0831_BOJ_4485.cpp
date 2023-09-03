#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int _map[125][125];
int dist[125][125];
int n;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs() {
	queue < pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = _map[0][0];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			//이전 좌표의 거리와 다음 좌표의 검은 루피의 합이
			//다음에 방문할 좌표의 거리보다 작은 경우 갱신하고 queue에 넣어 계속 탐색
			if (dist[nx][ny] > dist[x][y] + _map[nx][ny]) {
				dist[nx][ny] = dist[x][y] + _map[nx][ny];
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int problem = 0;
	while (true) {
		cin >> n;
		problem++;

		if (n == 0) break;

		//memset(dist, 999999999, sizeof(dist));

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) dist[i][j] = 999999999;

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++)
				cin >> _map[i][j];
		
		bfs();

		cout << "Problem " << problem << ": " << dist[n - 1][n - 1] << '\n';
	}

	return 0;
}