# 어떤 문제인지 감을 잡고
# 중요한 거 부터 정독하기
# 그냥 풀게되면 실수할 확률(문제를 잘 못 읽어서 잘 못 접근한 경우)

# 색종이 개수?

# for 문을 돌면서..

# 반복적으로 실행
# 이때 길이는 반으로 줄고, 줄은 길이는 반으로 준 길이를 더해주자.

# 입력
n =int(input())
paper = []
ans = [0,0]

for _ in range(n):
    paper.append(list(map(int, input().split())))
    
def dividePaper( x, y, n):
  color = paper[x][y]
  
  for row in range(x, x+n):
    for col in range(y, y+n):
      if color != paper[row][col]:  
        dividePaper(x, y, n//2) # 1
        dividePaper(x, y+n//2, n//2) # 2
        dividePaper(x+n//2, y, n//2) # 3
        dividePaper(x+n//2, y+n//2, n//2) # 4
        return 
  # 모든 범위 내 같은 색종이라면
  if color == 0:
    ans[0] += 1 # 하얀색
  else:
    ans[1] += 1 # 파란색


    
# 실행
dividePaper(0,0,n)

# 출력
for a in ans:
  print(a)
