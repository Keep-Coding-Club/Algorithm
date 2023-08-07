n = int(input())

for i in range(n):
    word = input()
    stack = []
    for j in word:
        if j=="(":
            stack.append(j)
        elif j==")" and "(" not in stack:
            stack.append(i)
        elif j==")":
            stack.pop()
    if stack==[]:
        print("YES")
    else:
        print("NO")