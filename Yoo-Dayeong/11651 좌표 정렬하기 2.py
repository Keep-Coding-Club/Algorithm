import sys

#1 코드 개선 
# 빠른 입력
input = sys.stdin.readline

n = int(input())

# board=[]
# for _ in range(n):
# 	x, y = map(int, input().split())
# 	board.append([x,y])
 
# sorted_board = sorted(board, key=lambda s: (s[1], s[0]))
                      
# for s in sorted_board:
# 	print(s[0], s[1])

#2 코드개선
# 딕셔너리의 key로 풀기
dic = {}

for _ in range(n):
  x, y = map(int, input().split())
  
  if y in dic:
    dic[y].append(x) # 1, 2
  else:
    dic[y]=[x]
    print([x])
    
key_list = list(dic.keys()) 

key_list.sort()

for key in key_list:
  ans = dic[key]
  ans.sort()
  for a in ans:
    print(f"{a} {key}")
    