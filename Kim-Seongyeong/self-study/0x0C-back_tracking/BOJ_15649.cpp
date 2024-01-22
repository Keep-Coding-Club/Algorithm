#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[8];
bool visited[9];

void dfs(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			num[level] = i;
			visited[i] = true;
			dfs(level + 1);
			//false�� �����ؾ� leve �� �ܰ��(level-1, level-1, ..)�� �� ���� Ž��(�湮)�� �� �ֱ� ����
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	dfs(0);

	return 0;
}