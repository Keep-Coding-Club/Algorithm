import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

M, N = map(int, input().split())
dp = [[-1] * N for _ in range(M)]
arr = [list(map(int, input().split())) for _ in range(M)]
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]


def dfs(x, y):
    # Base Case
    if x == M-1 and y == N-1:
        return 1
    # Visited Case
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = 0
    for i in range(4):
        newx = x + dx[i]
        newy = y + dy[i]
        if 0 <= newx < M and 0 <= newy < N:
            if arr[newx][newy] < arr[x][y]:
                dp[x][y] += dfs(newx, newy)
    return dp[x][y]


print(dfs(0, 0))

'''
1.DFS를 재귀로 구현할 때 RecursionError가 발생할 수 있으니 setrecursionlimit()을 설정해준다
2.DP를 -1로 초기화해서 방문했는지 체크한다
3.x, y가 오른쪽 맨 밑에 도달하면 1을 반환해준다
'''
