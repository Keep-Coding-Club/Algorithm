#include <stdio.h>
#include <iostream>
using namespace std;
int N, M;

int printArr[8];
bool visited[9];

void recurs(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++)
			cout << printArr[i] << ' ';
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			printArr[level] = i;
			recurs(level + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	recurs(0);
}