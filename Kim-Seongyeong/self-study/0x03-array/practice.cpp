/*
����)
�־��� ���� N�� int �迭 arr���� ���� 100�� ���� �ٸ� ��ġ�� �� ���Ұ� �����ϸ�
1��, �������� ������ 0�� ��ȯ�ϴ� �Լ� func2(int arr[], int N)�� �ۼ��϶�.
arr�� �� ���� 0 �̻� 100 �����̰�, N�� 1000 �����̴�.
*/

#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N) {
    int occur[101] = { 0 }; // ũ�� ���
    for (int i = 0; i < N; i++) {
        if (occur[100 - arr[i]] == 1)
            return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr1[] = { 1, 52, 48 };
    int arr2[] = { 50, 48 };

    cout << func2(arr1, 3) << "\n";
    cout << func2(arr2, 2) << "\n";

    return 0;
}
