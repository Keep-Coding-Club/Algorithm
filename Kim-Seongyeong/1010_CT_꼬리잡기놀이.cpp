#include <iostream>
#include <vector>

#define MAX_N 20
#define MAX_M 5
#define DIR_NUM 4

using namespace std;

int n, m, k;
int board[MAX_N + 1][MAX_N + 1];

// �� ���� ���� ��ġ�� �����մϴ�.
vector<pair<int, int> > v[MAX_M + 1];
// �� ���� tail ��ġ�� �����մϴ�.
int tail[MAX_M + 1];
bool visited[MAX_N + 1][MAX_N + 1];

// ���� �� ���Ͽ� �� �� ��ȣ�� �����ݴϴ�.
int board_idx[MAX_N + 1][MAX_N + 1];

int ans;

int dx[DIR_NUM] = { -1, 0, 1, 0 };
int dy[DIR_NUM] = { 0, -1, 0, 1 };

bool IsOutRange(int x, int y) {
	return !(1 <= x && x <= n && 1 <= y && y <= n);
}

// �ʱ� ������ ����� ���� dfs�� �̿��մϴ�.
void DFS(int x, int y, int idx) {
	visited[x][y] = true;
	board_idx[x][y] = idx;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsOutRange(nx, ny)) continue;

		// �̹� ������ ��ΰų� ��ΰ� �ƴϸ� �Ѿ�ϴ�.
		if (board[nx][ny] == 0) continue;
		if (visited[nx][ny]) continue;

		// ���� ó�� Ž���� �� 2�� �ִ� �������� dfs�� �����մϴ�.
		if ((int)v[idx].size() == 1 && board[nx][ny] != 2) continue;

		v[idx].push_back({ nx, ny });
		if (board[nx][ny] == 3) tail[idx] = (int)v[idx].size();
		DFS(nx, ny, idx);
	}
}

// �Է��� �޴� �� �ʱ� �۾��� �մϴ�.
void Init() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	int cnt = 1;

	// ������ ���Ϳ� �����մϴ�. �Ӹ������ �켱 �տ� �־��ݴϴ�.
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (board[i][j] == 1) v[cnt++].push_back({ i, j });

	// dfs�� ���� ������ ���Ϳ� ������� �־��ݴϴ�.
	for (int i = 1; i <= m; i++)
		DFS(v[i][0].first, v[i][0].second, i);
}

// �� ���� �̵���Ű�� �Լ��Դϴ�.
void MoveAll() {
	for (int i = 1; i <= m; i++) {
		// �� ���� ���� ������ �� ĭ�� �ڷ� �̵���ŵ�ϴ�.
		pair<int, int> tmp = v[i].back();
		for (int j = (int)v[i].size() - 1; j >= 1; j--)
			v[i][j] = v[i][j - 1];
		v[i][0] = tmp;
	}

	for (int i = 1; i <= m; i++) {
		// ���Ϳ� ������ ������ �������� ������ ǥ�� ���� �ٲ��ݴϴ�.
		for (int j = 0; j < (int)v[i].size(); j++) {
			pair<int, int> x = v[i][j];
			if (j == 0)
				board[x.first][x.second] = 1;
			else if (j < tail[i] - 1)
				board[x.first][x.second] = 2;
			else if (j == tail[i] - 1)
				board[x.first][x.second] = 3;
			else
				board[x.first][x.second] = 4;
		}
	}
}

// (x, y) ������ ���� ����� ���� ������ ����մϴ�.
void GetPoint(int x, int y) {
	int idx = board_idx[x][y];
	int cnt = 0;
	for (int i = 0; i < (int)v[idx].size(); i++)
		if (v[idx][i].first == x && v[idx][i].second == y) cnt = i;
	ans += (cnt + 1) * (cnt + 1);
}

// turn ��° ������ ���� �����ϴ�.
// ���� ������ �� �̸� ���� ���� ��ȣ�� ��ȯ�մϴ�.
int ThrowBall(int turn) {
	int t = (turn - 1) % (4 * n) + 1;

	if (t <= n) {
		// 1 ~ n ������ ��� ���ʿ��� ������ �������� ���� �����ϴ�.
		for (int i = 1; i <= n; i++) {
			if (1 <= board[t][i] && board[t][i] <= 3) {
				// ����� �ִ� ù ��° ������ ã���ϴ�.
				// ã�� �Ǹ� ������ üũ�� �� ã�� ����� �� ��ȣ�� �����մϴ�.
				GetPoint(t, i);
				return board_idx[t][i];
			}
		}
	}
	else if (t <= 2 * n) {
		// n+1 ~ 2n ������ ��� �Ʒ����� ���� �������� ���� �����ϴ�.
		t -= n;
		for (int i = 1; i <= n; i++) {
			if (1 <= board[n + 1 - i][t] && board[n + 1 - i][t] <= 3) {
				// ����� �ִ� ù ��° ������ ã���ϴ�.
				// ã�� �Ǹ� ������ üũ�� �� ã�� ����� �� ��ȣ�� �����մϴ�.
				GetPoint(n + 1 - i, t);
				return board_idx[n + 1 - i][t];
			}
		}
	}
	else if (t <= 3 * n) {
		// 2n+1 ~ 3n ������ ��� �����ʿ��� ���� �������� ���� �����ϴ�.
		t -= (2 * n);
		for (int i = 1; i <= n; i++) {
			if (1 <= board[n + 1 - t][n + 1 - i] && board[n + 1 - t][n + 1 - i] <= 3) {
				// ����� �ִ� ù ��° ������ ã���ϴ�.
				// ã�� �Ǹ� ������ üũ�� �� ã�� ����� �� ��ȣ�� �����մϴ�.
				GetPoint(n + 1 - t, n + 1 - i);
				return board_idx[n + 1 - t][n + 1 - i];
			}
		}
	}
	else {
		// 3n+1 ~ 4n ������ ��� ������ �Ʒ��� �������� ���� �����ϴ�.
		t -= (3 * n);
		for (int i = 1; i <= n; i++) {
			if (1 <= board[i][n + 1 - t] && board[i][n + 1 - t] <= 3) {
				// ����� �ִ� ù ��° ������ ã���ϴ�.
				// ã�� �Ǹ� ������ üũ�� �� ã�� ����� �� ��ȣ�� �����մϴ�.
				GetPoint(i, n + 1 - t);
				return board_idx[i][n + 1 - t];
			}
		}
	}
	// ���� �״�� �������ٸ� 0�� ��ȯ�մϴ�.
	return 0;
}

// ���� ȹ���� ���� ������ �ٲߴϴ�.
void Reverse(int got_ball_idx) {
	// �ƹ��� ���� ���� �������� �Ѿ�ϴ�.
	if (got_ball_idx == 0) return;

	int idx = got_ball_idx;

	vector<pair<int, int> > new_v;

	// ������ ���� new_v�� ������ �־��ݴϴ�.
	for (int i = tail[idx] - 1; i >= 0; i--) {
		pair<int, int> x = v[idx][i];
		new_v.push_back(x);
	}

	for (int i = (int)v[idx].size() - 1; i >= tail[idx]; i--) {
		pair<int, int> x = v[idx][i];
		new_v.push_back(x);
	}

	v[idx] = new_v;

	// ���Ϳ� ������ ������ �������� ������ ǥ�� ���� �ٲ��ݴϴ�.
	for (int j = 0; j < (int)v[idx].size(); j++) {
		pair<int, int> x = v[idx][j];
		if (j == 0)
			board[x.first][x.second] = 1;
		else if (j < tail[idx] - 1)
			board[x.first][x.second] = 2;
		else if (j == tail[idx] - 1)
			board[x.first][x.second] = 3;
		else
			board[x.first][x.second] = 4;
	}
}

int main() {
	// �Է��� �ް� ������ ���� �⺻���� ó���� �մϴ�.
	Init();

	for (int i = 1; i <= k; i++) {
		// �� ���� �Ӹ������ ���� ��ĭ�� �̵���ŵ�ϴ�.
		MoveAll();

		// i��° ������ ���� �����ϴ�. ���� ���� ����� ã�� ������ �߰��մϴ�.
		int got_ball_idx = ThrowBall(i);

		// ���� ȹ���� ���� ������ �ٲߴϴ�.
		Reverse(got_ball_idx);
	}

	cout << ans;
	return 0;
}

/*
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N, M, K;
int _map[20][20];
int dx[4] = { 0, -1, 0, 1};
int dy[4] = { 1, 0, -1, 0};

struct Info {
	int x; int y;
};

Info head[5];
Info tail[5];
Info ball;
int total = 0;


void move(int idx) {
	bool connect = false;
	int hx = -1, hy = -1;
	//1�� 3�� �Ű��ֱ�
	for (int i = 0; i < 4; i++) {
		int nx = head[idx].x + dx[i];
		int ny = head[idx].y + dy[i];

		if (_map[nx][ny] == 4) {
			_map[head[idx].x][head[idx].y] = 2;
			_map[nx][ny] = 1;
			head[idx].x = nx;
			head[idx].y = ny;
			break;
		}
		else if (_map[nx][ny] == 3) {
			_map[head[idx].x][head[idx].y] = 2;
			hx = head[idx].x;
			hy = head[idx].y;
			_map[nx][ny] = 1;
			head[idx].x = nx;
			head[idx].y = ny;
			connect = true;
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		int nx = tail[idx].x + dx[i];
		int ny = tail[idx].y + dy[i];

		if (_map[nx][ny] == 2) {
			if (nx == hx && ny == hy)
				continue;

			if (!connect) 
				_map[tail[idx].x][tail[idx].y] = 4;
			_map[nx][ny] = 3;
			tail[idx].x = nx;
			tail[idx].y = ny;
			break;
		}
	}

bool throwBall(int d, int cell) {
	int x, y;
	if (d == 0) {
		x = cell; y = 0;
	}
	else if (d == 1) {
		x = N - 1; y = cell;
	}
	else if (d == 2) {
		x = N - cell - 1; y = N - 1;
	}
	else {
		x = 0; y = N - cell - 1;
	}

	if (_map[x][y] == 1 || _map[x][y] == 2 || _map[x][y] == 3) {
		ball.x = x;
		ball.y = y;
		return true;
	}

	for (int i = 0; i < N; i++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;

		if (_map[nx][ny] == 1 || _map[nx][ny] == 2 || _map[nx][ny] == 3) {
			ball.x = nx;
			ball.y = ny;
			return true;
		}

		x = nx;
		y = ny;
	}
	return false;
}

void change(int x, int y) {
	int i;

	for (int j = 0; j < M; j++) {
		if (head[j].x == x && head[j].y == y) {
			i = j;
			break;
		}
	}

	Info temp;
	temp.x = head[i].x;
	temp.y = head[i].y;

	head[i].x = tail[i].x;
	head[i].y = tail[i].y;

	tail[i].x = temp.x;
	tail[i].y = temp.y;
}

int bfs(int inputX, int inputY) {
	int dist[20][20] = { 0, };
	bool visited[20][20] = { false, };
	queue<pair<int, int>> q;
	q.push({ inputX, inputY });
	dist[inputX][inputY] = 1;
	visited[inputX][inputY] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (_map[x][y] == 1) {
			change(x, y);
			return dist[x][y];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (visited[nx][ny])
				continue;

			if (_map[nx][ny] == 2 || _map[nx][ny] == 1) {
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	int p = 0, t = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 1) {
				head[p].x = i;
				head[p].y = j;
				p++;
			}
			else if (_map[i][j] == 3) {
				tail[t].x = i;
				tail[t].y = j;
				t++;
			}
		}
	}

	int round = 0;
	while (K--) {
		//1. ���� �̵�
		for (int i = 0; i < M; i++) {
			move(i);
		}

		//2. �� ������
		int d = (round / N)%4;
		int cell = round % N;
		int cnt=0;
		if (throwBall(d, cell)) {
			//3. ���� ȹ��
			cnt = bfs(ball.x, ball.y);
			total += pow(cnt, 2);
			//4. ���� ȹ���� ���� ���� �Ӹ� ���� ��ȯ
		}
		round++;
	}

	cout << total;

	return 0;
}
*/