'''
from itertools import combinations

n, m = map(int, input().split())
nums = []
for i in range(1, n+1):
    nums.append(i)

perm = list(combinations(nums, m))

for i in perm:
    for j in i:
        print(j, end=' ')
    print()


'''


# 백트래킹=> dfs 가지치기
def dfs(depth, i):
  if depth == m:  # 재귀함수로 반복 -> 함수 출력 조건을 먼저 걸어준다.
    print(' '.join(map(str, nums)))
    return
  for j in range(i+1, n+1):
    if not visited[j]:
      visited[j]=True
      
      nums.append(j)
      
      dfs(depth+1, j) # 다음
      visited[j]=False # 백트래킹
      nums.pop() #백트래킹

 
    
  
    

n, m = map(int, input().split())
nums = [] # 숫자가 담길 스택
visited= [False]*(n+1) # 이미 방문한 경우라면 제외하자.
dfs(0, 0)


'''
[문제 풀이]

1. N의 index가 헷갈리지 않게 N+1의 자연수화

2. 탈출 조건 depth == M 설정

3. 이전 자릿수보다 크게 되도록 for문에서 i+1 설정

4. 배열에 append 하면서 백트래킹
'''