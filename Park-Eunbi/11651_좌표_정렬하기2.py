# y 좌표가 증가하는 순으로 (같으면 x 좌표가 증가하는 순으로) 정렬
n = int(input())
nums = []
for _ in range(n):
    nums.append(list(map(int, input().split())))

nums.sort(key=lambda x: (x[1], x[0]))

for num in nums:
    print(*num)