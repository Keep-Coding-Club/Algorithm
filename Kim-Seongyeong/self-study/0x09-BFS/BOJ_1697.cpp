#include <bits/stdc++.h>
using namespace std;

int dist[100002]; //0부터 100000까지 사용하기 때문
int N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	fill(dist, dist + 100001, -1);

	queue<int> q; //좌표
	dist[N] = 0;
	q.push(N);

	//동생 좌표까지 언니가 도달할 때까지
	while (dist[K] == -1) {
		int x = q.front();
		q.pop();

		for (int nx : {x - 1, x + 1, x * 2}) {
			if (nx < 0 || nx > 100000)
				continue;
			if (dist[nx] != -1)
				continue;
			dist[nx] = dist[x] + 1;
			q.push(nx);
		}

		/*
		* for문을 사용하지 않고 일일히 확인하면 안되는 이유
		* -> continue로 인해 위에서 continue가 걸리면 다음 x+1 or x*2도 건너뛰기 때문
		int nx = x - 1;
		if (nx < 0 || nx > 100000)
			continue;
		if (dist[nx] != -1)
			continue;
		dist[nx] = dist[x] + 1;
		q.push(nx);

		nx = x + 1;
		if (nx < 0 || nx > 100000)
			continue;
		if (dist[nx] != -1)
			continue;
		dist[nx] = dist[x] + 1;
		q.push(nx);

		nx = x *2;
		if (nx < 0 || nx > 100000)
			continue;
		if (dist[nx] != -1)
			continue;
		dist[nx] = dist[x] + 1;
		q.push(nx);
		*/
	}

	cout << dist[K];

	return 0;
}