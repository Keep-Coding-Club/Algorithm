# 숫자카드 N개 중 숫자 M 카드를 몇개 가지고 있는지 반환

n = int(input())
cards = list(map(int, input().split()))
# cards.sort()

m = int(input())
search_cards = list(map(int, input().split()))
# search_cards.sort()

# 계수 정렬 - 배열의 인덱스 값을 활용하여 숫자 세기
## 제한 조건
## 1. 양수 2. 메모리 크기를 넘어가지 않아야 한다

plus_result = [0] * 10000002 # 0 포함
minus_result = [0] * 10000001 # index error 주의

for c in cards:
    if c >= 0:
        plus_result[c] += 1
    else:
        minus_result[-c] += 1

result = []
for s in search_cards:
    if s < 0:
        result.append(minus_result[-s])
    else:
        result.append(plus_result[s])

for r in result:
    print(r, end=' ')

