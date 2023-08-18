#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, cnt = 1;
	int num = 64, minCm = 64;

	cin >> x;	

	while (num>x) {
		minCm /= 2;
		if (num - minCm >= x) {
			num -= minCm;
		}
		else
			cnt++;
	}

	cout << cnt;

	return 0;
}