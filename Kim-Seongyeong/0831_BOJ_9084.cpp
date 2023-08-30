#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int dp[10001];

		for (int i = 0; i < 10001; i++) dp[i] = 0;
		dp[0] = 1;

		int n, m;
		int coin[21];

		cin >> n;
		//어떤 동전인지 입력
		for (int i = 0; i < n; i++) cin >> coin[i];

		cin >> m;
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= m; ++j) {
				dp[j] += dp[j - coin[i]];
			}
		}

		cout << dp[m] << '\n';
	}

	return 0;
}