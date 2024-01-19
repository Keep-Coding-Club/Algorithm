#include <bits/stdc++.h>
using namespace std;

int func(int r, int c, int n) {
	if (n == 0) return 0;

	int half = 1 << (n - 1);

	//몇 번째 사각형인지
	//1번 
	if (r < half && c < half)
		return func(r, c, n - 1);
	//2번
	if (r < half && c >= half)
		return half * half + func(r, c - half, n - 1);
	//3번
	if (r >= half && c < half)
		return 2 * half * half + func(r - half, c, n - 1);
	//4번
	return 3 * half * half + func(r - half, c - half, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, r, c;
	cin >> N >> r >> c;

	cout << func(r, c, N);

	return 0;
}