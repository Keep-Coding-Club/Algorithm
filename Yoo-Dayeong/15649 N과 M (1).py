# 1부터 n까지 자연수 중 중복없이 m개를 고른 수열
# 수열은 오름차순 정렬해 반환

# nPm
'''
from itertools import permutations

n, m = map(int, input().split())
nums = []
for i in range(1, n+1):
    nums.append(i)

perm = list(permutations(nums, m))

for i in perm:
    for j in i:
        print(j, end=' ')
    print()
'''

# 백트래킹=> dfs 가지치기
def dfs():
  if len(nums) == m:  # 재귀함수로 반복 -> 함수 출력 조건을 먼저 걸어준다.
    print(' '.join(map(str, nums)))
    return
  for i in range(1, n+1):
    if visited[i]: # 이미 방문했다면..
      continue
    visited[i]=True
    nums.append(i)
    dfs()
    nums.pop()

    visited[i]=False
    
    
  
    

n, m = map(int, input().split())
nums = [] # 숫자가 담길 스택
visited= [False]*(n+1) # 이미 방문한 경우라면 제외하자.
dfs()

'''
n m
3 1
'''
'''
1
2
3
'''
