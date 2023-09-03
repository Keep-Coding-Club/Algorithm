# 2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.

x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

ans = (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)

if ans > 0:
    print(1)  # 반시계
elif ans < 0:
    print(-1)  # 시계
else:
    print(0)  # 일직선

# 풀이 과정
# 세 점으로 이뤄진 삼각형의 면적을 구하는 방법을 이용해 방향성 구할 수 있음을 사용
# https://www.acmicpc.net/blog/view/27
