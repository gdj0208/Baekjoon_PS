
from itertools import combinations

def count_all_combs(arr) :
    count = 0
    all_combs = []

    for i in range(1, len(arr)+1) :
        all_combs.extend(list(combinations(arr, i)))

    for comb in all_combs :
        sum = 0

        for num in comb :
            sum += 1/num
        
        if 0.99 <= sum and sum <= 1.01 : 
            count += 1

    return count
    


count = 0
size = int(input())
arr = list(map(int, input().split()))

# arr.sort()

print(count_all_combs(arr))