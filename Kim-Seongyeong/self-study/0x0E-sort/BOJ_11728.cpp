#include <bits/stdc++.h>
using namespace std;

int a[1000000], b[1000000];
int result[2000000];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < M; i++)
		cin >> b[i];

	//병합 정렬 구현
	int aIdx = 0, bIdx = 0;
	for (int i = 0; i < N + M; i++) {
		if (bIdx == M)
			result[i] = a[aIdx++];
		else if (aIdx == N)
			result[i] = b[bIdx++];
		else if (a[aIdx] < b[bIdx]) {
			result[i] = a[aIdx];
			aIdx++;
		}
		else {
			result[i] = b[bIdx];
			bIdx++;
		}
	}

	for (int i = 0; i < N + M; i++)
		cout << result[i] << ' ';

	return 0;
}