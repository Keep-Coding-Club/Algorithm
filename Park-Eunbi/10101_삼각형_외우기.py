# 세 각의 크기가 모두 60이면, Equilateral
# 세 각의 합이 180이고, 두 각이 같은 경우에는 Isosceles
# 세 각의 합이 180이고, 같은 각이 없는 경우에는 Scalene
# 세 각의 합이 180이 아닌 경우에는 Error

triangles = []
for _ in range(3):
    triangles.append(int(input()))

triangles.sort()

if sum(triangles) == 180:
    if triangles[0] == triangles[1] == triangles[2] == 60:
        print('Equilateral')
    elif triangles[0] == triangles[1]:
        print('Isosceles')
    elif triangles[0] == triangles[2]:
        print('Isosceles')
    elif triangles[1] == triangles[2]:
        print('Isosceles')
    else:
        print('Scalene')

else:
    print('Error')


'''
if a == 60 and b == 60 and c == 60:
  print('Equilateral')
elif a + b + c == 180:
  if a == b or b == c or c == a:
        print('Isosceles')
  elif a != b or b != c or c != a:
        print('Scalene')
else:
  print('Error')
'''