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

	//���ѵ� ����ŭ arr�� ��Ұ� true�Ǿ�� �ϴ� ���� �ƴ϶�
	//arr�� ��� ��ҵ��� true or false �̹Ƿ�
	//�׳� sum�� �ָ� ������ ���� ����
	//sum + arr[level]�̸� ���� ����
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