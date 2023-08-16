# 자연수
# 1 ≤ S ≤ 4,294,967,295

s = int(input())

# 서로 다른 n개의 자연수의 합이 s
# n의 최댓값?


sum = 0
cnt_n = 0  # n의 최댓값 세기 위한 변수

for i in range(1, s+1):
    sum += i
    cnt_n += 1

    if sum > s:
        break

if s == 1:  # 자연수 1일때는 예외처리
    print(cnt_n)
else:
    print(cnt_n-1)  # s를 초과하는 것이므로 -1


# s까지 하나씩 증가해가면서 더하고 만약 s보다 크다면.. 반복 종료
