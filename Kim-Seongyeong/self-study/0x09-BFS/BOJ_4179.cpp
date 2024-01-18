/*
불과 지훈 누가 먼저 도착하느냐
-> 불의 BFS를 다 돈 후에 지훈이 BFS를 돌릴 때 
불의 전파보다 지훈이가 빠른 경우만 채움

반례 모음
https://forward-gradually.tistory.com/52
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[1000][1000];
int fire[1000][1000];
int jihun[1000][1000];
int dx[4] = { -1,0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	queue<pair<int, int>> q;
	cin >> N >> M;
	int fx, fy, jx, jy;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j];
			//불의 시작점이 여러 개일 수 있으니 큐에 다 넣어줌
			if (board[i][j] == 'F') {
				q.push({ i, j });
			}
			else if (board[i][j] == 'J') {
				jx = i;
				jy = j;
			}
		}
	}

	//불의 이동 시간 BFS
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny] == '.' && fire[nx][ny] == 0) {
				fire[nx][ny] = fire[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	//지훈의 이동 시간 BFS
	//불보다 짧을 때만 기록 가능
	q.push({ jx, jy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//범위를 벗어나면 탈출 성공
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				cout << jihun[x][y] + 1;
				return 0;
			}
				
			if (board[nx][ny] == '.' && jihun[nx][ny] == 0) {
				if (fire[nx][ny] == 0 || jihun[x][y] + 1 < fire[nx][ny]) {
					jihun[nx][ny] = jihun[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}