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
			//false로 변경해야 leve 전 단계들(level-1, level-1, ..)이 이 곳을 탐색(방문)할 수 있기 때문
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