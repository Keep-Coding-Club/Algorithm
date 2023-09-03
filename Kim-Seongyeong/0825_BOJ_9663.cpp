#include <iostream>
#include <stdio.h>

using namespace std;

int n, cnt=0;
int _map[15]; //_map[i]�� x��ǥ, i�� y��ǥ

bool check(int level) {
	for (int i = 0; i < level; i++) {
		//1. _map[i] == _map[level] : queen�� ���� ��, ���� ��ġ�ϴ��� Ȯ��
		//2.  abs(_map[level] - _map[i]) == level - i : �밢���� ��ġ�ϴ��� Ȯ��
		if (_map[i] == _map[level] || abs(_map[level] - _map[i]) == level - i)
			return false;
	}
	return true;
}

void backTracking(int queen) {
	//backTracking �߿� queen�� ������ n�� ��ġ�ϸ�
	//��� queen�� ���� ������ �� ���� ��Ȳ�̹Ƿ� cnt ���� �ϳ� ����
	if (queen == n)	cnt++;

	else {
		for (int i = 0; i < n; i++) {
			//�� ��° ���� ��� ���� ��ġ�Ѵ�.
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