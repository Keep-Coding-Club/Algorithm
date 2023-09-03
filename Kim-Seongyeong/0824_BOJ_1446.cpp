#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> minDis(10001, 9999999); //�� i�� ���� �ּ� ���(DP)
vector<pair<int, int>> v[10001]; //index�� ������ ���� ��ġ <int, int>�� ������ ������ ��ġ�� ����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, d;

	cin >> n >> d;

	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b > d || b - a < c) continue; //������ �������� d�� ����ų� �������� ���̰� b-a���� ũ�� v�� �߰����� ����
		v[b].push_back({ a, c });
	}

	minDis[0] = 0;

	//DP minDis ä��� ����
	for (int i = 1; i <= d; i++) {
		//�켱, minDis �� ������ 1�� ���ϸ� �ּ� �Ÿ��� �Է�
		minDis[i] = minDis[i - 1] + 1;

		//i�� ���� �������� �ִ��� Ȯ��
		for (int j = 0; j < v[i].size(); j++) {
			//minDis[v[i][j].first] - ������ ��������� ���� �ּ� �Ÿ�
			//v[i][j].second - ������ �Ÿ�

			//���� �� ����� �հ� minDis[i]�� �ּ� ���� minDis[i]�� ����
			minDis[i] = min(minDis[i], minDis[v[i][j].first] + v[i][j].second);
		}
	}

	cout << minDis[d];

	return 0;
}