# 일곱 난쟁이 모자 위 수의 합 == 100
# 아홉 난쟁이 모자 위 수가 주어졌을 때 일곱 난쟁이 구하기

nums = []
for _ in range(9):
    nums.append(int(input()))

all_sum = sum(nums)
remove_a = 0
remove_b = 0
# 두 쌍씩 골라 all_sum에서 빼주기
for i in range(9 - 1):
    for j in range(i + 1, 9):
        check_no = nums[i] + nums[j]
        # print(i, j)
        if all_sum - check_no == 100:
            remove_a, remove_b = i, j
            # 여기서 지우면 index error!
            # for 문을 돌고 있는 중이기에 삭제하면 error가 남 (2개 연속으로 삭제해야 해서 break 도 못 검)
            # nums.remove(nums[i])
            # nums.remove(nums[j])
            # nums.pop(i)
            # nums.pop(j - 1)
            break

nums.pop(remove_a)
nums.pop(remove_b - 1) # 인덱스를 사용하기에 위에서 삭제한 1개를 빼 주어야 한다

for n in nums:
    print(n)