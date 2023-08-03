# 올바르게 구성된 괄호이면 YES, 아니면 NO 출력

'''
'('이면 넣고, ')'이면 저장된 '('을 삭제
끝까지 돌았는데도 괄호가 남아있으면 NO

'NO' 판정 경우
1. '('가 더 많은 경우
    반복문을 돌아도 '('가 남아 있음
2. ')'가 더 많은 경우
    스택에 '('가 없음에도 ')'을 삭제하려 함 - 에러
'''

n = int(input())
parenthesis = []
for _ in range(n):
    parenthesis.append(list(input()))

for p in parenthesis:
    p_stack = []
    for c in p:
        if c =='(':
            p_stack.append('(')
        else: # c == ')'
            try:
                p_stack.pop()
            except: # 'NO' 판정 2번
                print('NO')
                break
    else:
        if p_stack: # len(p_stack) > 0, 'NO' 판정 1번
            print('NO')
        else:
            print('YES')