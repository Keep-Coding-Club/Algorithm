#include <iostream>
#include <stdio.h>

using namespace std;

int n, cnt=0;
int _map[15]; //_map[i]는 x좌표, i은 y좌표

bool check(int level) {
	for (int i = 0; i < level; i++) {
		//1. _map[i] == _map[level] : queen이 같은 행, 열에 위치하는지 확인
		//2.  abs(_map[level] - _map[i]) == level - i : 대각선이 위치하는지 확인
		if (_map[i] == _map[level] || abs(_map[level] - _map[i]) == level - i)
			return false;
	}
	return true;
}

void backTracking(int queen) {
	//backTracking 중에 queen의 개수가 n과 일치하면
	//모든 queen이 서로 공격할 수 없는 상황이므로 cnt 개수 하나 증가
	if (queen == n)	cnt++;

	else {
		for (int i = 0; i < n; i++) {
			//몇 번째 퀸이 어디 열에 위치한다.
			_map[queen] = i;
			if (check(queen))
				backTracking(queen + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	backTracking(0);
	
	cout << cnt;

	return 0;
}