# 삼각형 종류 구분
# 세 각의 크기가 모두 60 -> Equilateral
# 세 각의 합이 180 and 두 각이 같은 경우 -> Isosceles
# 세각의 합이 180 and 같은 각이 없는 경우 -> Scalene
#  세 각의 합이 180 아닌 경우 -> Error

a = int(input())
b = int(input())
c = int(input())

if a == b == c == 60:
  print("Equilateral")
elif a+b+c == 180:
  if a==b or b==c or a==c:
    print("Isosceles")
  if not( a==b or b==c or a==c):
    print("Scalene")
else:
  print("Error")
  