#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[20];
int cnt = 0;
bool visited[20];

void dfs(int sum, int level) {
	if (level == N) {
		if (sum == S)
			cnt++;
		return;
	}

	//제한된 수만큼 arr의 요소가 true되어야 하는 것이 아니라
	//arr의 모든 요소들이 true or false 이므로
	//그냥 sum을 주면 더하지 않은 상태
	//sum + arr[level]이면 더한 상태
	dfs(sum, level + 1);
	dfs(sum + arr[level], level + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dfs(0, 0);

	if (S == 0) cnt--;
	cout << cnt;

	return 0;
}