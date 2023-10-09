#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct People {
	int x = -1;
	int y = -1;
};

bool visited[15][15]; //갈 수 없는 좌표
int _map[15][15];
vector<pair<int, int>> market;
int n, m, t = 0;
int pSum;
vector<pair<int, int>> base;
People people[30];

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

//최단 경로로 한칸 이동하기
void bfs(int idx, pair<int, int> mart) {
	bool visi[15][15] = { false, };

	queue<pair<int, int>> q;
	q.push({ mart.first,  mart.second });
	visi[mart.first][mart.second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx == people[idx].x && ny == people[idx].y) {
				cout << x << ", " << y << '\n';
				people[idx].x = x;
				people[idx].y = y;
				return; //break가 아니라 return으로 while문 탈출해야 함
			}

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (visited[nx][ny])
				continue;

			if (visi[nx][ny])
				continue;

			
			q.push({ nx, ny });
			visi[nx][ny] = true;
		}
	}
}

//베이스 찾기
People gotoBase(int idx) {
	int mx = market[idx].first, my = market[idx].second;

	People minInfo;

	int minDist = 9999;
	for (int i = 0; i < base.size(); i++) {
		if (visited[base[i].first][base[i].second])
			continue;

		bool visi[15][15] = { false, };
		queue<pair<pair<int, int>, int>> q;
		q.push({ {base[i].first, base[i].second}, 0 });
		visi[base[i].first][base[i].second] = true;

		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dist = q.front().second;
			q.pop();

			if (dist > minDist)
				break;

			if (x == mx && y == my) {
				if (dist < minDist) {
					minInfo.x = base[i].first;
					minInfo.y = base[i].second;

					minDist = dist;
				}
				else if (dist == minDist) {
					if (base[i].first < minInfo.x) {
						minInfo.x = base[i].first;
						minInfo.y = base[i].second;
					}
					else if (base[i].first == minInfo.x) {
						if (base[i].second < minInfo.y) {
							minInfo.x = base[i].first;
							minInfo.y = base[i].second;
						}
					}
				}
				break;
			}

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (visited[nx][ny])
					continue;
				if (visi[nx][ny])
					continue;
				
				q.push({ {nx, ny}, dist + 1 });
				visi[nx][ny] = true;
			}
		}

	}
	return minInfo;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	pSum = m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> _map[i][j];
			if (_map[i][j]) base.push_back({ i, j });
		}
	}

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		_map[x-1][y-1] = 2; //편의점
		market.push_back({ x - 1, y - 1 });
	}

	while (pSum) {
		t++;
		
		//1. 최단거리로 한칸 이동
		for (int i = 0; i < m; i++) {
			if (people[i].x != -1){
				bfs(i, market[i]);
			}
			//2. 편의점 도착시 visited 갱신 & pSum--a
			if (people[i].x == market[i].first && people[i].y == market[i].second) {
				visited[market[i].first][market[i].second] = true;
				pSum--;
				people[i].x = -1;
				people[i].y = -1;
			}
		}

		//3. 사람 베이스 캠프로 이동
		//가까운 베캠 찾아주고, people의 x, y 값 갱신
		if (t <= m) {
			People base;
			base = gotoBase(t-1);
			cout <<"base : "<< base.x << ", " << base.y << '\n';

			people[t-1].x = base.x;
			people[t-1].y = base.y;
			visited[base.x][base.y] = true;
		}
	}

	cout << t;

	return 0;
}