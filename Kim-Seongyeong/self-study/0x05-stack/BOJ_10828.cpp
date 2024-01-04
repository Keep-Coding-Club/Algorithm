//stack 직접 구현하기

#include <bits/stdc++.h>
using namespace std;

int dat[100000];
int pos;

void push(int val) {
	dat[pos++] = val;
}

void pop() {
	pos--;
}

int top() {
	return dat[pos - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		if (s == "push") {
			int t;
			cin >> t;
			push(t);
		}
		else if (s == "pop") {
			if (pos == 0)
				cout << "-1\n";
			else {
				cout << top() << '\n';
				pop();
			}
		}
		else if (s == "size")
			cout << pos << '\n';
		else if (s == "empty")
			cout << (int)(pos == 0) << '\n';
		else {
			if (pos == 0)
				cout << "-1\n";
			else
				cout << top() << '\n';
		}
	}

	return 0;
}