# 재귀로 풀기
# n : 3의 거듭제곱
# 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 있는 패턴
# n > 3 : 공백으로 채워진 가운데에 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴

n = int(input())

def star(n):
    if n == 3:
        return ['***', '* *', '***']

    # 반환된 값 arr에 추가
    arr = star(n//3)
    # 최종 결과값 담을 리스트
    stars = []

    # 반환된 리스트를 하나씩 돌며 확장해나감
    for i in arr:
        stars.append(i*3)

    # 빈 공간을 채워감
    for i in arr:
        stars.append(i + ' ' * (n//3) + i)

    for i in arr:
        stars.append(i * 3)

    return stars

# star() 리턴값에 '\n' join
# return ['***', '* *', '***'] -> '***\n* *\n***'
print('\n'.join(star(n)))