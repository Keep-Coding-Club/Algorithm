#include <bits/stdc++.h>
using namespace std;

int dist[100002]; //0���� 100000���� ����ϱ� ����
int N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	fill(dist, dist + 100001, -1);

	queue<int> q; //��ǥ
	dist[N] = 0;
	q.push(N);

	//���� ��ǥ���� ��ϰ� ������ ������
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
		* for���� ������� �ʰ� ������ Ȯ���ϸ� �ȵǴ� ����
		* -> continue�� ���� ������ continue�� �ɸ��� ���� x+1 or x*2�� �ǳʶٱ� ����
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