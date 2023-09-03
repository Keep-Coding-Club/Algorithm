t = int(input())
tree_array = []
for _ in range(t):
    n = int(input())
    tree_array.append(list(map(int, input().split())))

for tree in tree_array:
    tree.sort(reverse= True)

    new_tree_list = [tree.pop(0)]

    for _ in range((len(tree) + 1 )// 2):
        try:
            tmp_1 = tree.pop(0)
            tmp_2 = tree.pop(0)
            new_tree_list.insert(0, tmp_1)
            new_tree_list.append(tmp_2)
        except:
            new_tree_list.insert(0, tmp_1)

    tree = new_tree_list

    ret = abs(tree[0] - tree[-1])
    for i in range(len(tree) - 1):
        abs_temp = abs(tree[i] - tree[i + 1])
        ret = max(abs_temp, ret)

    print(ret)