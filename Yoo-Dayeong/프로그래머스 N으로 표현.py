# 일단 가능한 경우의 수를 모두 구하되, 그전의 계산해놓은 게 쓰이니까 dp
'''
처음엔 number에 대한 dp 테이블을 생성해서 문제를 풀려했는데, 그게 아니라 N의 사용 횟수에 대한 dp 테이블을 이용해 문제를 해결
문제에서 최솟값이 8보다 클 경우 -1을 반환한다고 나와있으므로 N을 8번 사용하는 경우까지만 계산하면 된다.
'''

from collections import defaultdict


def solution(N, number):
    dp = defaultdict(set)
    # N 사용 횟수
    for i in range(1, 9):
        dp[i].add(int(str(N) * i))  # NNN..N

        for j in range(1, i):
            # j 개
            for num1 in dp[j]:
                # i-j 개
                for num2 in dp[i - j]:  # 현재 연산 횟수 i에서 사용할 숫자 개수 j를 뺀다
                    dp[i].add(num1 + num2)
                    dp[i].add(num1 - num2)
                    dp[i].add(num1 * num2)
                    if num2 != 0:
                        dp[i].add(num1 // num2)
                        # number가 연산한 결과에 있으면 답으로 반환
        if number in dp[i]: # N을 i번 사용해서 number를 만들 수 있음
            return i
    return -1


print(solution(5, 12))
