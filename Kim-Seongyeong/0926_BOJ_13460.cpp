#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct bead {
	int rx, ry;
	int bx, by;
	int d; //기울인 횟수
};

int n, m;
int map[10][10];
bool visited[10][10][10][10];
queue<bead> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void move(int& x, int& y, int& c, int& i) {
	//#와 O를 만나서 더 이상 이동할 수 없을 때까지 한쪽 방향(i)으로 이동 
	while (map[x + dx[i]][y + dy[i]] != '#' && map[x][y] != 'O') {
		x += dx[i];
		y += dy[i];
		c += 1;
	}
}

void bfs() {
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int d = q.front().d; //빨간 구슬과 파란 구슬의 해당 위치일 때 기울인 횟수

		q.pop();
		if (d >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, nd = d + 1;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (map[nbx][nby] == 'O') continue;
			if (map[nrx][nry] == 'O') {
				cout << nd;
				return;
			}

			//구슬이 겹쳤을 때
			if (nrx == nbx && nry == nby) {
				//이동거리가 더 긴 구슬을 한칸 뒤로
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (!visited[nrx][nry][nbx][nby]) {
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx, nry, nbx, nby, nd });
			}
		}
	}
	cout << -1;
}


int main() {
	ios::sync_with_stdio(0);
	int rx, ry, bx, by;

	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'R') rx = i, ry = j;
			else if (map[i][j] == 'B') bx = i, by = j;
		}
		cin.ignore();
	}

	q.push({ rx, ry, bx, by, 0 });
	visited[rx][ry][bx][by] = true;
	bfs();
}