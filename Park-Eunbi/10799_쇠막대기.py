# 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다
# 포함되도록 놓되, 끝 점이 겹쳐서는 안된다
# '()'은 레이저, '(', ')'은 쇠막대기

# 1. 레이저를 만나면 stack에 쌓인 '(' 의 개수 만큼 쇠막대기가 생긴다
# 2. ')'를 만나면 쇠막대기의 끝지점이기에 1개의 막대기만 절단된다

bars = input()
bar_stack = []
ret = 0

for i, b in enumerate(bars):
    if b == '(':
        bar_stack.append('(')
    else: # b == ')'
        if bars[i-1] == '(': # '()' 형태인 레이저인지 판단
            bar_stack.pop() # 하나 꺼내고
            ret += len(bar_stack) # 남아있는 '(' 개수 만큼 쇠막대기가 잘림
        else: # ')' 을 만났지만 레이저가 아닌 경우
            bar_stack.pop() # 하나 꺼내고
            ret += 1 # 한 번 잘림 (쇠막대기 조각)

print(ret)

