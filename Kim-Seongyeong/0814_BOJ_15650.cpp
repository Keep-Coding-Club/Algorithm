#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
bool visitied[9];
int arr[8];

//Q15649 - N과 M(1)과 다른 점은 오름차순을 어떻게 구현할 것인가

void recurs(int level, int num) {
	if (level == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	//recurs의 매개변수 중 num을 넘겨줘서 
	//num부터 for문을 돌기 시작하여 오름차순을 구현
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