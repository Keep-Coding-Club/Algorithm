#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    //최솟값이 8보다 크면 return -1
    int answer = -1;

    //idx개 만큼 만들 수 있는 연산식의 정보
    //ex) DP[2] = { 55, 5 + 5, 5 - 5, 5 * 5, 5 / 5 }
    set<int> dp[8]; 

    int num = 0;
    for (int i = 0; i < 8; i++) {
        num = 10 * num + N; // N, NN, NNN, NNNN ... 만들기
        dp[i].insert(num);
    }

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j - 1]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0)
                        dp[i].insert(a / b);
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        if (dp[i].count(number)) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}