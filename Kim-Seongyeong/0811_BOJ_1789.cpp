#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	long long int sum = 0, i=1, cnt=0;

	long long int n;
	cin >> n;

	while (true) {
		sum += i;
		cnt++;
		if (sum > n) {
			cnt--;
			cout << cnt;
			break;  
		}
		i++;
	}

	return 0;
}