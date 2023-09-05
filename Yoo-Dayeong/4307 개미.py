import sys

t = int(sys.stdin.readline())

for _ in range(t):
    l, n = map(int, sys.stdin.readline().split())
    ant = [int(sys.stdin.readline()) for _ in range(n)]
    f_ant = 0
    l_ant = 0

    # 모든 개미를 확인
    for i in ant:
        # 개미의 위치가 막대의 우측에 있다면
        if i > l - i:
            # 가장 빠른 시간에 떨어질 경우
            if f_ant < l - i:
                f_ant = l - i

            # 가장 늦은 시간에 떨어질 경우
            if l_ant < i:
                l_ant = i

        # 개미의 위치가 막대의 좌측에 있다면
        else:
            if f_ant < i:
                f_ant = i

            if l_ant < l - i:
                l_ant = l - i

    print(f_ant, l_ant)

# 풀이
'''
- 모든 개미의 위치를 확인하면서 막대 기준 좌측과 우측에 가까운지 확인한다.

- 두 경우에서 개미가 가장 빠른 시간에 떨어질 경우와 가장 늦은 시간에 떨어질 경우를 구한다.

- 두 개미가 만났을 때 방향을 바꿔야 하는 경우는 신경 쓰지 않고 문제를 수행한다.(결국 개미의 번호가 없다면 두 개미는 가려고 하는 방향을 계속 가는 것이기 때문.)
'''