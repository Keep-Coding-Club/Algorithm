# number 를 N을 사용하여 표현, 그 중 가장 N을 적게 사용한 경우 반환

# dp - 작게 나누어 판단
# N을 1개, 2개 ,,, 사용하여 만들 수 있는 수의 집합 생각해보기
'''
N == 5, 
1번 사용 -> 5 
2번 사용 -> 55, 5 + 5, 5 - 5, 5 / 5, 5 * 5
3번 사용 ->
555, 
55 + 5, 55 - 5, 55 / 5, 55 * 5
5 + 5 + 5, 5 - 5 - 5, 5 / 5 / 5, 5 * 5 * 5
'''

'''
n번 이어 붙여서 만든 수 
1번 사용해서 표현한 수 집합 (사칙 연산) n - 1 번 사용해서 표현한 수 집합
2번 사용해서 표현한 수 집합 (사칙 연산) n - 2 번 사용해서 표현한 수 집합
                    	.
                        .
                        .
                    
n - 1번 사용해서 표현한 수 집합 (사칙 연산) 1 번 사용해서 표현한 수 집합
'''

# 결론: 1 ~ 8개의 N을 사용해서 만들 수 있는 수의 집합 중에 number가 처음 나오는 개수를 리턴

def solution(N, number):
    if number == 1:
        return 1
    set_list = []

    for cnt in range(1, 9):  # 1개부터 8개까지 확인
        partial_set = set()
        partial_set.add(int(str(N) * cnt))  # 이어 붙여서 만드는 경우 넣기
        for i in range(cnt - 1):  # (1, n-1) 부터 (n-1, 1)까지 사칙연산
            for op1 in set_list[i]:
                for op2 in set_list[-i - 1]:
                    partial_set.add(op1 + op2)
                    partial_set.add(op1 * op2)
                    partial_set.add(op1 - op2)
                    if op2 != 0:
                        partial_set.add(op1 / op2)
        # 만든 집합에 number가 처음 나오는지 확인
        if number in partial_set:
            return cnt
        set_list.append(partial_set)
    return -1
