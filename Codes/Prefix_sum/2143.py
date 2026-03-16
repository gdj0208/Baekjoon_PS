
"""
T에 대해 (1, T-1) ~ (T-1, 1)까지 
- A에서 최대값, B에서 최대값을 더함
- 이 값의 최대값을 고름
"""
from collections import Counter

def get_sum_list(my_list, list_size) :
    sum_list = []
    
    for i in range(list_size) :
        sum = 0
        for j in range(i, list_size):
            sum += my_list[j]
            sum_list.append(sum)

    return sum_list


T = int(input())
size_A = int(input())
A = list(map(int, input().split()))
size_B = int(input())
B = list(map(int, input().split()))

sum_A = get_sum_list(A, size_A)
sum_B = get_sum_list(B, size_B) 

countB = Counter(sum_B)
cnt = 0
for sum in sum_A :
    target =T -sum
    cnt += countB[target]

print(cnt)