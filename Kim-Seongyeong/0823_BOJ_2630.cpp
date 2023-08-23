#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int _map[128][128];
int blueCnt = 0, whiteCnt = 0;

void search(int x, int y, int len) {
	int flag = _map[x][y];

	for (int i = x; i < x+len; i++) {
		for (int j = y; j < y+len; j++) {
			if (flag != _map[i][j]) {
				search(x, y, len / 2);
				search(x + len / 2, y, len / 2);
				search(x, y + len / 2, len / 2);
				search(x + len / 2, y + len / 2, len / 2);

				//분할 정복시 핵심 분할하면 return을 사용하여 해당 단계는 끝내야 한다.
				return;
			}
		}
	}

	(flag == 0) ? whiteCnt++ : blueCnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> _map[i][j];
		}
	}

	search(0, 0, n);

	cout << whiteCnt << '\n' << blueCnt;

	return 0;
}