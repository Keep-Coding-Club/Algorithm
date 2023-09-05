# 문제: https://www.acmicpc.net/problem/1991

# 이진 트리 노드 개수
n = int(input())

tree = {}  # 키, 값을 이용하기 위한 딕셔너리 사용

for _ in range(n):
    root, left, right = map(str, input().split())
    tree[root] = [left, right]


# 전위=dfs
def preorder(root):
    if root != '.':
        print(root, end='')  # root
        preorder(tree[root][0])  # 왼쪽
        preorder(tree[root][1])  # 오른쪽


# 중위
def inorder(root):
    if root != '.':
        inorder(tree[root][0])  # 왼쪽
        print(root, end='')  # root
        inorder(tree[root][1])  # 오른쪽


# 후위
def postorder(root):
    if root != '.':
        postorder(tree[root][0])  # 왼쪽
        postorder(tree[root][1])  # 오른쪽
        print(root, end='')  # root


# 항상 'A'가 루트노드임.
preorder('A')
print()
inorder('A')
print()
postorder('A')

'''
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
'''
