# 부분수열에서 처음부터 끝까지 증가하는 횟수가 몇번이 되는지 count할때 가장 수가 큰 부분수열을 구하는 문제

n = int(input())
arr = list(map(int, input().split()))

dp = [1] * n  # 자기자신으로 이뤄진 수열은 길이가 1이므로 1으로 초기화

for cur in range(1, n):
    for front in range(0, cur):
        if arr[front] < arr[cur]:  # 나보다 앞에 있는게 더 작다면(크거나 같다면 가장 긴 증가하는 부분 수열이 될 수 없다)
            dp[cur] = max(dp[cur], dp[front] + 1)  # 이전 숫자들 중 최댓값 구하고, 길이에 1 더해줌
print(max(dp))
