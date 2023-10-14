#include <iostream>
using namespace std;

int n, m, d, p;
//�� �� �� �� �� �� �� ��
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

long long rebro[15][15];
bool nut[15][15];

void nutMove() {
	bool temp[15][15] = { false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nut[i][j]) {
				int x = i;
				int y = j;

				int nx = (x + dx[d] * p + n) % n;
				int ny = (y + dy[d] * p + n) % n;

				temp[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nut[i][j] = temp[i][j];
		}
	}
}

void growup() {
	//������ �ִ� ��ġ 1�� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nut[i][j]) {
				rebro[i][j]++;
			}
		}
	}

	//�밢�� ����μ� ��ŭ ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nut[i][j]) {
				int cnt = 0;
				int x = i, y = j;
				for (int k = 1; k < 8; k+=2) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (rebro[nx][ny])
						cnt++;
				}
				rebro[i][j] += cnt;
			}			
		}
	}
}

void nutSetting() {
	bool temp[15][15] = { false, };
	//����μ� 2 �̻��� �� -> 2��ŭ �ڸ��� & ������ �÷���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nut[i][j])
				continue;
			if (rebro[i][j] >= 2) {
				rebro[i][j] -= 2;
				temp[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nut[i][j] = temp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> rebro[i][j];
		}
	}

	//�ʱ� ������ ��ġ ����
	nut[n - 1][0] = true; nut[n - 1][1] = true;
	nut[n - 2][0] = true; nut[n - 2][1] = true;

	while (m--) {
		cin >> d >> p;
		d--;

		/*cout << "\n------- before ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << nut[i][j] << ' ';
			}
			cout << '\n';
		}*/

		//������ �̵�
		nutMove();

		/*cout << "\n------- before ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << nut[i][j] << ' ';
			}
			cout << '\n';
		}*/

		//������ ����(������ ����) & �밢�� ����μ���ŭ ���� ����
		/*cout << "\n------- before ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << rebro[i][j] << ' ';
			}
			cout << '\n';
		}*/
		growup();
		/*cout << "\n------- after ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << rebro[i][j] << ' ';
			}
			cout << '\n';
		}*/

		//������ �߰�
		/*cout << "\n------- before ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << nut[i][j] << ' ';
			}
			cout << '\n';
		}*/
		nutSetting();
		/*cout << "\n------- after ----------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << nut[i][j] << ' ';
			}
			cout << '\n';
		}*/
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result += rebro[i][j];
		}
	}

	cout << result;

	return 0;
}