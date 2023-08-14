# n이 3의 거듭제곱일대, 크기 n의 패턴은 nxn 정사각형 모양임.
# 기본형 -> 3의 패턴
# 가운데 공백, 가운데를 제외한 모든 칸에 별이 하나씩있음.
'''
***
* *
***

# n의 패턴은 공백으로 채워진 가운데의 (n/3) x (n/3) 정사각형을 n/3의 패턴으로 둘러싼 형태
# 재귀적으로 계속해 반복

'''

# def counting_star(a:list):
#   ans = []

#   for i in range(3 * len(a)):
#     if (i//len(a)==1):
#       ans.append(a[i%len(a)] + " "* len(a) + a[i%len(a)])
#     else:
#       ans.append(a[i%len(a)]*3)
#   return ans

# # 기본형 -> 3의 패턴
# star = ["***", "* *", "***"]

# n = int(input())
# cnt = 0

# while n!=3:
#   n = n//3
#   cnt += 1
# # cnt 값을 통해 재귀함수의 횟수 결정
# for i in range(cnt):
#   star =  counting_star(star)

# for s in star:
#   print(s)


'''
느낀점

역시 재귀함수는 실제로 코드로 구상하려면 어렵다.
쫄지말고 쪼개서 생각하자
'''

# 좌표계 이용

import sys


def star(i, j, n):
    if n == 1:  # 정사각형의 변이라면(N x N 정사각형 크기가 1이라면)
        print("*", end="")
    elif (i//(n//3)) % 3 == 1 and (j//(n//3)) % 3 == 1:  # 정사각형의 가운데라면
        print(" ", end="")  # 공백 출력
    else:
        star(i, j, n//3)  # 정사각형의 크기를 n/3로 줄인 후 정사각형 중간에 위치한 공백인지 재탐색


n = int(sys.stdin.readline()) # 빠른 입력

# 정사각형이므로 이중 for문
for i in range(n):
    for j in range(n):
        star(i, j, n)
    print()
