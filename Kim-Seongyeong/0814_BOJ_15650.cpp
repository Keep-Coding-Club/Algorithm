#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
bool visitied[9];
int arr[8];

//Q15649 - N�� M(1)�� �ٸ� ���� ���������� ��� ������ ���ΰ�

void recurs(int level, int num) {
	if (level == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	//recurs�� �Ű����� �� num�� �Ѱ��༭ 
	//num���� for���� ���� �����Ͽ� ���������� ����
	for (int i = num; i <= N; i++) {
		if (!visitied[i]) {
			visitied[i] = true;
			arr[level] = i;
			recurs(level + 1, i + 1);
			visitied[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> N >> M;

	recurs(0, 1);

	return 0;
}