#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	string inputStr;

	cin >> n;
	while (n--) {
		cin >> inputStr;
		stack<char> s;
		bool noFlag = false;

		for (int i = 0; i < inputStr.length(); i++) {
			if (inputStr[i] == '(') {
				s.push(inputStr[i]);
			}
			else {
				if (s.empty()) {
					cout << "NO\n";
					noFlag = true;
					break;
				}
				else
					s.pop();
			}
		}

		if (!noFlag) {
			if (s.empty())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}