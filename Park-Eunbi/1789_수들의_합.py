# 서로다른 n 개의 자연수의 합: s
# n 의 최댓값

s = int(input())

# 최대한 많은 자연수를 사용하려면 서로 다른 자연수가 최소가 되어야 한다
# 1부터 다 더해보면 된다

total = 0
count = 0

while 1:
    count += 1 # 1, 2, 3, ...
    total += count # 1, 3, 6, ...
    if total > s:
        break

print(count -1) # 1씩 증가시키기 때문