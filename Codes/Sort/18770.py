import copy

rpt = int(input())
nums = list(map(int, input().split()))
cpy = sorted(list(set(nums)))
rnks = {}
    
rnks = { val : i for i, val in enumerate(cpy) }

for num in nums:
    print(rnks[num], end=" ")