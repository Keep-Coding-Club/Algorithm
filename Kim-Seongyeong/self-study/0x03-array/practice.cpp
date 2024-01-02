/*
문제)
주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면
1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
arr의 각 수는 0 이상 100 이하이고, N은 1000 이하이다.
*/

#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N) {
    int occur[101] = { 0 }; // 크기 명시
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
