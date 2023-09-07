# 구역을 4개의 선거구로 나누고, 각 구역은 다섯 선거구 중 하나에 포함
# 선거누는 구역을 적어도 하나 포함, 한 선거구에 포함된 구역은 모두 연결
# 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값 출력

# d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
# x+d1+d2 ≤ N ->  x <= N - 2 => 1 < x < N - 2
# y+d2 ≤ N -> y <= N - 1
# 1 ≤ y-d1 -> 2 <= y
# => 2 <= y <= N - 1

n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
total = 0 # 5번 구역의 인구수를 구하기 위해 사용
for row in matrix:
    total += sum(row) # 전체 인구수 구하기
answer = int(1e9) # 최솟값을 구하는 것이기에 최댓값으로 초기화

def calculate(row, col, d1, d2):
    global total, answer
    first, second, third, fourth = 0, 0, 0, 0

    # 구역 1: (x, y), (x+1, y-1), ..., (x+d1, y-d1)
    col1 = col + 1 # 인덱스 차이때문에 더함
    for r in range(row + d1):
        if r >= row:
            col1 -= 1 # 이거 왜 함 -> 1번 구역의 경계: (x, y), (x+1, y-1), ..., (x+d1, y-d1)
        first += sum(matrix[r][:col1]) # 경계 내 행 더하기

    # 구역 2: (x, y), (x+1, y+1), ..., (x+d2, y+d2)
    col2 = col + 1
    for r in range(row + d2 + 1): # 직선 경계 때문에 + 1
        if r > row:
            col2 += 1
        second += sum(matrix[r][col2:])

    # 구역 3: (x, y), (x+1, y-1), ..., (x+d1, y-d1)
    col3 = col - d1
    for r in range(row + d1, n):
        third += sum(matrix[r][:col3])
        if r < row + d1 + d2:
            col3 += 1

    # 구역 4: (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
    col4 = (col + d2) - n
    for r in range(row + d2 + 1, n):
        fourth += sum(matrix[r][col4:])
        if r <= row + d1 + d2:
            col4 -= 1

    # 구역 5
    five = total - first - second - third - fourth
    answer = min(answer, (max(first, second, third, fourth, five) - min(first, second, third, fourth, five)))

def check(r, c, d1, d2): # 가능한 d1, d2 찾기
    if 0 <= r + d1 - 1 < n and 0 <= r + d2 - 1 < n and 0 <= c - d1 + d2 - 1 < n:
        if 0 <= c - d1 and c + d2 < n and r + d1 + d2 < n:
            calculate(r, c, d1, d2)

for r in range(n-2):
    for c in range(1, n-1):
        for d1 in range(1, n-1):
            for d2 in range(1, n-1):
                check(r, c, d1, d2)

print(answer)

'''
# 다른 풀이 - 경계 matrix를 만들고 합 구하기 

def gerry(N, A, x, y, d1, d2):
    M = [[0 for _ in range(N)] for _ in range(N)]
    # 경계선 5로 표시
    for i in range(d1 + 1):
        if not (0 <= x + i < N and 0 <= y - i < N):
            return -1
        M[y - i][x + i] = 5
    for i in range(d2 + 1):
        if not (0 <= x + i < N and 0 <= y + i < N):
            return -1
        M[y + i][x + i] = 5
    for i in range(d2 + 1):
        if not (0 <= x + d1 + i < N and 0 <= y - d1 + i < N):
            return -1
        M[y - d1 + i][x + d1 + i] = 5
    for i in range(d1 + 1):
        if not (0 <= x + d2 + i < N and 0 <= y + d2 - i < N):
            return -1
        M[y + d2 - i][x + d2 + i] = 5

    # 1, 2, 3, 4 구역 칠하기
    for c in range(0, x + d1 + 1):
        for r in range(0, y):
            if M[r][c] == 5:
                break
            M[r][c] = 1
    for r in range(0, y - d1 + d2 + 1):
        for c in range(N - 1, x + d1, -1):
            if M[r][c] == 5:
                break
            M[r][c] = 2
    for c in range(0, x + d2 + 2):
        for r in range(N - 1, y - 1, -1):
            if M[r][c] == 5:
                break
            M[r][c] = 3
    for r in range(y - d1 + d2 + 1, N):
        for c in range(N - 1, x + d2 - 1, -1):
            if M[r][c] == 5:
                break
            M[r][c] = 4
    # 인구 수 구하기
    res = [0, 0, 0, 0, 0]
    for r in range(N):
        for c in range(N):
            if M[r][c] in (0, 5):
                res[0] += A[r][c]
            else:
                res[M[r][c]] += A[r][c]
    return max(res) - min(res)


def solution():
    N = int(sys.stdin.readline().strip())
    A = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]

    gerry(N, A, 1, 3, 2, 2)
    result = []
    for x in range(N):
        for y in range(N):
            for d1 in range(1, int(N * 1.414) + 1):
                for d2 in range(1, int(N * 1.414) + 1):
                    element = gerry(N, A, x, y, d1, d2)
                    if element == -1:
                        break
                    else:
                        result.append(element)

    print(min(result))


solution()
'''
