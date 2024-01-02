#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int alpabetCnt[26] = { 0, };
	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		alpabetCnt[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alpabetCnt[i] << ' ';
	}

	return 0;
}