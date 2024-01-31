/*
Greedy 알고리즘
	= 지금 가장 최적인 답을 근시안적으로 택하는 알고리즘
	= 관찰을 통해 탐색 범위를 줄이는 알고리즘 
*/

/*
11047은 동전이 배수인 경우 -> 그리디 사용
https://www.acmicpc.net/problem/11047

2294는 동전이 배수 X 경우 -> DP 사용
https://www.acmicpc.net/problem/2294
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	int coin[10];
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += k / coin[n - i - 1];
		k %= coin[n - i - 1];
	}

	cout << cnt;

	return 0;
}