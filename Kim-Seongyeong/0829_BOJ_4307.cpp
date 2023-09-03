#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int l, n;
		int minSec = 0, maxSec = 0;
		cin >> l >> n;
		for (int i = 0; i < n; i++) {
			int inputX;
			cin >> inputX;

			int shortSec = min(inputX, l - inputX);
			int longSec = max(inputX, l - inputX);

			if (maxSec < longSec)
				maxSec = longSec;
			if (minSec < shortSec)
				minSec = shortSec;
		}

		cout << minSec << " " << maxSec << '\n';
	}

	return 0;
}