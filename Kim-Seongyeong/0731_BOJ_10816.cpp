#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, inputNum;
	vector<int> v;

	cin >> n;
	while (n--) {
		cin >> inputNum;
		v.push_back(inputNum);
	}

	sort(v.begin(), v.end());

	cin >> m;

	int targetNum;
	while (m--) {
		cin >> targetNum;

		//입력 받은 수가 vector에서 처음 등장하는 index 반환
		//이때, lower의 경우 찾는 수가 vector에 없을 때 자신보다 큰 수의 등장 위치 반환
		int lowIdx = lower_bound(v.begin(), v.end(), targetNum) - v.begin();
		//입력 받은 수보다 큰 수가 vector에서 처음 등장하는 index 반환
		int upIdx = upper_bound(v.begin(), v.end(), targetNum) - v.begin();
		
		//따라서 그 수가 끝난 위치와 시작된 위치를 빼면 개수를 알 수 있고,
		//vector에 존재하지 않는 경우 lower와 upper의 위치가 같기 때문에 0개를 반환
		cout << upIdx-lowIdx << ' ';
	}

	return 0;
}