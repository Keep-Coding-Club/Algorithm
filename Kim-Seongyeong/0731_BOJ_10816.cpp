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

		//�Է� ���� ���� vector���� ó�� �����ϴ� index ��ȯ
		//�̶�, lower�� ��� ã�� ���� vector�� ���� �� �ڽź��� ū ���� ���� ��ġ ��ȯ
		int lowIdx = lower_bound(v.begin(), v.end(), targetNum) - v.begin();
		//�Է� ���� ������ ū ���� vector���� ó�� �����ϴ� index ��ȯ
		int upIdx = upper_bound(v.begin(), v.end(), targetNum) - v.begin();
		
		//���� �� ���� ���� ��ġ�� ���۵� ��ġ�� ���� ������ �� �� �ְ�,
		//vector�� �������� �ʴ� ��� lower�� upper�� ��ġ�� ���� ������ 0���� ��ȯ
		cout << upIdx-lowIdx << ' ';
	}

	return 0;
}