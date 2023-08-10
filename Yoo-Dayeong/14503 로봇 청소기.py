'''
1. 현재 위치를 청소
2. 현재 위치, 현재 방향 기준(반시계 방향==왼쪽 방향부터 탐색)
2-1. 왼쪽 방향에 아직 청소 안한 경우, 그 방향으로 회전 후 한 칸 전진 -> 1번 부터 진행
2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전 후 -> 2번 부터 진행
2-3. 네 방향 모두 청소가 되어있거나 벽인 경우, 바라보는 방향 유지한채 -> 한 칸 후진, 2번으로
2-4. 네 방향 모두 청소가 되어있거나 후진 불가 -> 작동 stop

#1. arr[ci][cj] <- 2(청소), cnt += 1
#2. 왼쪽 방향부터 4방향 탐색
for 빈곳: arr[ni][nj] == 0
  새로운 방향, 좌표 갱신
else
  후진할 위치가 벽이 아니라면: "후진"
  벽이라면: "종료"
'''
# dr: 북, 동, 남, 서
di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]

# solution
def robotic_vacuum(ci, cj, dr):
  cnt = 0 # 청소한 칸
  
  while 1: # 벽이라면 종료
    # [1] 현재 위치를 청소
    arr[ci][cj]=2
    cnt +=1
    
    # [2] 왼쪽 방향부터 탐색
    flag = 1
    while flag==1:
      for i in ((dr+3)%4, (dr+2)%4, (dr+1)%4, dr):
        ni = ci + di[i]
        nj = cj + dj[i]
        if arr[ni][nj]==0: # 미청소 영역
          ci, cj, dr = ni, nj, i
          flag = 0
          break
      else: # 4방향 모두 미청소 영역 없음 -> 후진
        bi = ci - di[dr]
        bj = cj - dj[dr]
        if arr[bi][bj] ==1: # 벽
          return cnt
        else:
          ci, cj = bi, bj
  # -1 이라면 내부 로직이 이상하다는 의미
  return -1 
        
        
      
  

# 입력
n, m = map(int, input().split())
si, sj, dr = map(int, input().split()) # start i, start j, dr(direction) 설정
# 방
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

ans = 0
print(robotic_vacuum(si, sj, dr))

