#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	list<char> cursor;

	string str;
	cin >> str;

	for (auto s : str) cursor.push_back(s);
	//list<char>::iterator it = cursor.begin();
	list<char>::iterator it = cursor.end();


	int orderCnt;
	cin >> orderCnt;

	char order, alpa;
	for (int i = 0; i < orderCnt; i++) {
		cin >> order;

		if (order == 'L') {
			if (it == cursor.begin())
				continue;
			it--;
		}
		else if (order == 'D') {
			if (it == cursor.end())
				continue;
			it++;
		}
		else if (order == 'B') {
			if (it == cursor.begin())
				continue;
			it--;
			it = cursor.erase(it);
		}
		else {
			cin >> alpa;
			cursor.insert(it, alpa);
		}
	}

	for (list<char>::iterator i = cursor.begin(); i != cursor.end(); i++)
		cout << *i;

	return 0;
}