import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    coins = list(map(int, input().split()))
    m = int(input())

    # memoization을 위한 리스트 선언
    d = [0] * (m + 1)
    d[0] = 1


    for coin in coins:
        for i in range(m + 1):
            # a_(i-k) 를 만드는 방법이 존재한다면 
            # 이전 경우의 수에 현재 동전으로 만들 수 있는 경우의 수를 더한다.
            if i >= coin:
                d[i] += d[i - coin]

    print(d[m])
    
    
'''
풀이
동전이 오름차순으로 정렬되어 주어지기 때문에 작은 동전부터 해당 동전을 이용하여 m 원을 만들 수 있는 경우의 수를 더한 뒤, 다음 동전으로 넘어가서 이전 경우의 수에 해당 동전으로 만들 수 있는 경우의 수를 순차적으로 더해가며 답을 구한다.

1. 반복문으로 코인을 돈다
2. 1원부터 m원까지 돈(i) - 코인(k) => 0보다 크다면 코인으로 만들 수 있는 돈 
3. dp[i] += dp[i - k] 
4. 위 식의 i - k의 경우 이전에 dp의 저장된 i - k번 째의 수를 가져와 사용하는 것을 의미 

https://velog.io/@whddn0221/백준-9084-동전-다이나믹-프로그래밍-파이썬
'''