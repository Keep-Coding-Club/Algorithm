#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> minDis(10001, 9999999); //길 i로 가는 최소 비용(DP)
vector<pair<int, int>> v[10001]; //index는 지름길 시작 위치 <int, int>는 지름길 끝나는 위치와 길이

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, d;

	cin >> n >> d;

	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b > d || b - a < c) continue; //지름길 도착지가 d를 벗어나거나 지름길의 길이가 b-a보다 크면 v에 추가하지 않음
		v[b].push_back({ a, c });
	}

	minDis[0] = 0;

	//DP minDis 채우는 과정
	for (int i = 1; i <= d; i++) {
		//우선, minDis 전 과정에 1을 더하면 최소 거리라 입력
		minDis[i] = minDis[i - 1] + 1;

		//i로 가는 지름길이 있는지 확인
		for (int j = 0; j < v[i].size(); j++) {
			//minDis[v[i][j].first] - 지름길 출발지까지 오는 최소 거리
			//v[i][j].second - 지름길 거리

			//위의 두 요소의 합과 minDis[i]의 최소 값을 minDis[i]로 설정
			minDis[i] = min(minDis[i], minDis[v[i][j].first] + v[i][j].second);
		}
	}

	cout << minDis[d];

	return 0;
}