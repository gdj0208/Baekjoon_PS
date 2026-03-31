
def LIS_Algorithm(lists, size) :
    dp = [1 for _ in range(size)]
    for i in range(1, size) :
        for j in range(0, i) :
            if lists[j] < lists[i] :
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)


size = int(input())
lines = {}

for _ in range(size) :
    l1, l2 = map(int, input().split())
    lines[l1] = l2

sorted_lines = sorted(lines.keys())
target_list = [lines[k] for k in sorted_lines]

print(size - LIS_Algorithm(target_list, size))