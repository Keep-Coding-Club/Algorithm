#include <iostream>
#include <queue>
using namespace std;

int N, M;
int _map[20][20];
bool visited[20][20];
long long score = 0;
//idx - 0 : ��, 1 : ������ ������, 2 : �Ʒ�, 3 : ������ ����, 4 : ������ ����, 5 : ������ ����
int dNum[6] = { 1,3,6,4,5,2 }; 

//��, ��, ��, ��
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct Dice {
	int x = 0; int y = 0; int dir = 0;
};

Dice dice;

int selectDir() {
	int x = dice.x, y = dice.y, d = dice.dir;
	if (dNum[2] > _map[x][y]) {
		d = (d + 1) % 4;
		int nx = x + dx[d];
		int ny = y + dy[d];

		//���� ����� ���� �ٲٱ�
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			d = (d + 2) % 4;
			nx = x + dx[d];
			ny = y + dy[d];
		}

		dice.x = nx; dice.y = ny; dice.dir = d;
	}
	else if (dNum[2] < _map[x][y]) {
		d = (d - 1 + 4) % 4;		
		int nx = x + dx[d];
		int ny = y + dy[d];

		//���� ����� ���� �ٲٱ�
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			d = (d + 2) % 4;
			nx = x + dx[d];
			ny = y + dy[d];
		}

		dice.x = nx; dice.y = ny; dice.dir = d;
	}
	else {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			d = (d + 2) % 4;
			nx = x + dx[d];
			ny = y + dy[d];
		}

		dice.x = nx; dice.y = ny; dice.dir = d;
	}

	return dice.dir;
}

void changeDice(int num) {
	//������ �̵�
	if (num == 0) {
		int temp = dNum[3];
		dNum[3] = dNum[2]; dNum[2] = dNum[1]; dNum[1] = dNum[0]; dNum[0] = temp;
	}
	//�Ʒ�(������) �̵�
	else if (num == 1) {
		int temp = dNum[5];
		dNum[5] = dNum[0]; dNum[0] = dNum[4]; dNum[4] = dNum[2]; dNum[2] = temp;
	}
	//���� �̵�
	else if (num == 2) {
		int temp = dNum[3];
		dNum[3] = dNum[0]; dNum[0] = dNum[1]; dNum[1] = dNum[2]; dNum[2] = temp;
	}
	//�� �̵�
	else if (num == 3) {
		int temp = dNum[5];
		dNum[5] = dNum[2]; dNum[2] = dNum[4]; dNum[4] = dNum[0]; dNum[0] = temp;
	}
}

long long bfs(int inputX, int inputY) {
	queue<pair<int, int>> q;
	int num = _map[inputX][inputY];
	q.push({ inputX, inputY });
	visited[inputX][inputY] = true;

	int cnt = 0;

	while (!q.empty()) {
		cnt++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (visited[nx][ny])
				continue;
			if (_map[nx][ny] == num) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}

	return num * cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> _map[i][j];
		}
	}

	dice.y = 1;
	changeDice(0);
	score += bfs(dice.x, dice.y);
	M--;


	while (M--) {
		//�ֻ��� �̵�
		//���� ���ϱ� -> �̵� & �ֻ��� ��(dNum)�� ����
		changeDice(selectDir());


		//���� ȹ��
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		score += bfs(dice.x, dice.y);
	}
	
	cout << score;

	return 0;
}