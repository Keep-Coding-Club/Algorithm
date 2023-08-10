# i -> j 가는 길에 양수인 경로가 있는지 없는지 구하기
# 1: 존재, 0: 없음
# 주의! 자기 자신으로 가는 직접적인 경로는 없다. 다른 노드를 통해 돌아와야만 한다

from collections import deque

n = int(input())
maps = []
for _ in range(n):
    maps.append(list(map(int, input().split())))

# bfs
visited = [[0] * n for _ in range(n)]

def bfs(x):
    queue = deque()
    queue.append(x)
    check = [0 for _ in range(n)]

    while queue:
        q = queue.popleft()

        for i in range(n):
            if check[i] == 0 and maps[q][i] == 1:
                queue.append(i)
                check[i] = 1
                visited[x][i] = 1

for i in range(0, n):
    bfs(i)

for i in visited:
    print(*i) # print 할 때 * 붙이면 [0, 0, 0] -> 0 0 0 으로 출력

'''
# 플로이드 워셜
# 모든 최단 경로를 구하는 알고리즘 (모든 정점에 대한 경로를 계산하는 알고리즘)
# cf) 다익스트라: 한 정점에서 다른 모든 정점까지 최단 거리를 구하는 알고리즘 
# 거쳐가는 노드 
for k in range(n):
    # 시작 노드 
    for i in range(n):
        # 도착 노드 
        for j in range(n):
            if maps[i][j] == 1 or (maps[i][k] == 1 and maps[k][j] == 1):
                maps[i][j] = 1

for m in maps:
    print(*m)

'''