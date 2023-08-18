# 숫자 간격 사이 값을 최소로 통나무 배치

# 배열을 오름차순 정렬, i-2 차이가 가장 큰 값
import sys

input = sys.stdin.readline

t = int(input())

for i in range(t):
    ans = 0
    len = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    for j in range(2, len):
        ans = max(ans, arr[j]-arr[j-2])
    print(ans)
'''
3
7
13 10 12 11 10 11 12
5
2 4 5 7 9
8
6 6 6 6 6 6 6 6
'''
