# 가중치 없는 방향 그래프 g
# 모든 정점 (i, j)에 대해 i에서 j로 가는 길이 양수인 경로가 있는지 없는지 구하기


# 그래프 - 인접행렬
# 1: i에서 j로 가는 간선 존재
# 0: i에서 j로 가는 간선 없음

# 정점 개수
N = int(input())
 
inputMap = [[0 for col in range(0, N)] for row in range(0, N)]
 
for i in range(0, N) :
    for j, m in enumerate(map(int, input().split())) :
        inputMap[i][j] = m
 
# 플로이드 워셜 알고리즘(Floyd Warshall Algorithm) 이용
# 모든 정점에 대한 경로를 계산하는 알고리즘
for k in range(0, N) :
    for i in range(0, N) :
        for j in range(0, N):
            if inputMap[i][k] and inputMap[k][j] :
                inputMap[i][j] = 1
 
for i in range(0, N) :
    _str = ""
    for j in range(0, N) :
        _str += str(inputMap[i][j]) +  " "
    print(_str)
 
