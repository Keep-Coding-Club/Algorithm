N = int(input())
population = [list(map(int, input().split())) for _ in range(N)]


def solve():
    min_ans = 20 * 20 * 100  # 인구 값 차이를 최댓값으로 리셋

    for x in range(N):
        for y in range(N):
            for d1 in range(1, N + 1):
                for d2 in range(1, N + 1):
                    # 나머지 세 모서리가 범위 내에 있어야 한다.
                    if (0 <= x + d1 < N and 0 <= y - d1 < N) and (0 <= x + d2 < N and 0 <= y + d2 < N) and (
                            0 <= x + d1 + d2 < N and 0 <= y - d1 + d2 < N):
                        section = [[5 for _ in range(N)] for _ in range(N)]

                        # 1번 구역 설정
                        for i in range(d1 + 1):
                            r1, c1 = x + i, y - i
                            for tr in range(r1):
                                section[tr][c1] = 1

                        r2, c2 = x + d1, y - d1
                        for tc in range(c2):
                            for tr in range(r2):
                                section[tr][tc] = 1

                        # 2번 구역 설정
                        for i in range(d2 + 1):
                            r1, c1 = x + i, y + i
                            for tc in range(c1 + 1, N):
                                section[r1][tc] = 2

                        r2, c2 = x, y
                        for tr in range(r2):
                            for tc in range(c2 + 1, N):
                                section[tr][tc] = 2

                        # 3번 구역 설정
                        for i in range(d2 + 1):
                            r1, c1 = x + d1 + i, y - d1 + i
                            for tc in range(c1):
                                section[r1][tc] = 3

                        r2, c2 = x + d1 + d2, y - d1 + d2
                        for tr in range(r2 + 1, N):
                            for tc in range(c2):
                                section[tr][tc] = 3

                        # 4번 구역 설정
                        for i in range(d1 + 1):
                            r1, c1 = x + d2 + i, y + d2 - i
                            for tr in range(r1 + 1, N):
                                section[tr][c1] = 4

                        r2, c2 = x + d2, y + d2
                        for tc in range(c2 + 1, N):
                            for tr in range(r2 + 1, N):
                                section[tr][tc] = 4

                        cal = [0 for _ in range(6)]  # 5번 구역까지

                        for r in range(N):
                            for c in range(N):
                                sec = section[r][c]
                                cal[sec] += population[r][c]
                        ans = max(cal[1:]) - min(cal[1:])  # 1~5번 구역의 최댓값-최솟값

                        if min_ans > ans:
                            min_ans = ans

    print(min_ans)


solve()


'''
6
1 2 3 4 1 6
7 8 9 1 4 2
2 3 4 1 1 3
6 6 6 6 9 4
9 1 9 1 9 5
1 1 1 1 9 9
'''
# https://rhdtka21.tistory.com/82

