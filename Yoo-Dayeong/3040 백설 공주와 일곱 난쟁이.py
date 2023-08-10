# 아홉 개의 수 중 합이 100이 되는 일곱개의 수?
import random

nine = []
for i in range(9):
    nine.append(int(input()))

sum_value = 0
seven = []

# 1. 아홉 개의 수의 합을 구한다.
# 2. 이때 아홉 개의 수중에서 2개를 추출
# 3. 추출한 값을 뺐을때 100이 되는 일곱개의 수를 출력

for n in nine:
    sum_value += n

flag = 1
while (flag == 1):
    two = random.sample(nine, 2)
    if sum_value-sum(two) == 100:
        seven = [n for n in nine if n not in two]
        break

# print(seven)
for _ in seven:
    print(_)
