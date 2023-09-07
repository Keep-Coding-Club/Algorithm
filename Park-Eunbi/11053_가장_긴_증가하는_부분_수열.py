n = int(input())
nums = list(map(int, input().split()))
dp = [0] * n

'''
10 20 10 30 20 50
'''

for i in range(n):
    for j in range(i):
        if nums[i] > nums[j] and dp[i] < dp[j]:
            dp[i] = dp[j]
    dp[i] += 1

print(max(dp))