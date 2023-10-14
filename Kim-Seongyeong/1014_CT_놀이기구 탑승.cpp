#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int n;
int _map[20][20];
bool candi[20][20];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

struct Like {
	int student[4];
};

queue<pair<int, Like>> q;
Like studentInto[401];

int sNum;
Like sLike;

int check(int x, int y, Like sl) {
	int cnt = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (_map[nx][ny] == sl.student[0] || _map[nx][ny] == sl.student[1] || _map[nx][ny] == sl.student[2] || _map[nx][ny] == sl.student[3])
			cnt++;
	}

	return cnt;
}

int check2(int x, int y) {
	int cnt = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;

		if (!_map[nx][ny])
			cnt++;
	}

	return cnt;
}

bool step1() {
	int maxNum = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j])
				continue;

			int num = check(i, j, sLike);
			if (num > maxNum) {
				for (int a = 0; a < n; a++)
					for (int b = 0; b < n; b++)
						candi[a][b] = false;
				candi[i][j] = true;
				maxNum = num;
			}
			else if (num == maxNum)
				candi[i][j] = true;

		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (candi[i][j])
				cnt++;

	if (cnt == 1)
		return true;
	return false;
}

bool step2() {
	int maxNum = -1;
	bool temp[20][20] = { false, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (candi[i][j]) {
				int num = check2(i, j);

				if (num > maxNum) {
					for (int a = 0; a < n; a++)
						for (int b = 0; b < n; b++)
							temp[a][b] = false;
					temp[i][j] = true;
					maxNum = num;
				}
				else if (num == maxNum)
					temp[i][j] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			candi[i][j] = temp[i][j];
			if (temp[i][j])
				cnt++;
		}

	if (cnt == 1)
		return true;
	return false;
}

void step3and4() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (candi[i][j]) {
				_map[i][j] = sNum;
				return;
			}
		}
	}
}

long long getScore() {
	long long score = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int s = _map[i][j];
			cnt = check(i, j, studentInto[s]);

			//cout << studentInto[s].student[0] << ", " << studentInto[s].student[1] << ", " << studentInto[s].student[2] << ", " << studentInto[s].student[3] << "\n";

			score += pow(10, cnt - 1);
		}
	}

	return score;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int s;
	Like sl;
	for (int i = 0; i < n * n; i++) {
		cin >> s >> sl.student[0] >> sl.student[1] >> sl.student[2] >> sl.student[3];
		q.push({ s,sl });
		studentInto[s] = sl;
	}

	int test = 1;
	while (!q.empty()) {
		/*cout << "\n\n-------- map ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << _map[i][j] << ' ';
			cout << '\n';
		}*/

		//cout << "******** test : " << test++ << "++++++++\n";
		sNum = q.front().first;
		sLike = q.front().second;
		q.pop();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				candi[i][j] = false;


		//1번
		/*cout << "\n\n-------- before ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << candi[i][j] << ' ';
			cout << '\n';
		}*/


		if (step1()) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (candi[i][j]) {
						_map[i][j] = sNum;
						break;
					}
				}
			}
			continue;
		}

		/*cout << "\n\n-------- after1 ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << candi[i][j] << ' ';
			cout << '\n';
		}*/

		//2번
		if (step2()) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (candi[i][j]) {
						_map[i][j] = sNum;
						break;
					}
				}
			}
		}

		/*cout << "\n\n-------- after2 ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << candi[i][j] << ' ';
			cout << '\n';
		}*/

		//3번 & 4번
		step3and4();
	}

	cout << getScore();

	return 0;
}