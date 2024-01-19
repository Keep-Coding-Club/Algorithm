#include <bits/stdc++.h>
using namespace std;

/*
* func 함수를 계속 따라들어가는 절차지향적 사고를 버리고,
* 귀납적으로 접근하여
* n은 1일때 잘 동작, n은 k 일 때도, k+1일 때도 잘 동작
*/

void func(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	//n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다
	func(a, 6 - a - b, n - 1);
	//n번 원판을 기둥 a에서 기둥 b로 옮긴다
	cout << a << ' ' << b << '\n';
	//n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
	func(6 - a - b, b, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k;
	cin >> k;

	//비트 연산 : 1을 비트 기준으로 k칸 밀어라
	cout << (1 << k) - 1 << '\n';

	//원판 k개를 1번 기둥에서 3번 기둥으로 옮기는 방법
	func(1, 3, k);
}