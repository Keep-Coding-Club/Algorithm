#include <bits/stdc++.h>
using namespace std;

int n;
int roof[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> roof[i];
	}

	sort(roof, roof + n);

	int result = 0;
	//로프 개수(i)를 선택해서 최대 중량을 갱신
	//roof[n-i]는 i개 선택할 때 최대 중량이 되기 위해 선택된 로프 중 가장 작은 중량
	for (int i = 1; i <= n; i++)
		result = max(result, roof[n - i] * i);

	cout << result;
}