#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), compare);

	for (auto i : v)
		cout << i.first << ' ' << i.second << '\n';

	return 0;
}