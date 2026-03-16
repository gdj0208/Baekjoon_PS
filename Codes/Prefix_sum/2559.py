import sys
N, K = map(int, input().split())
arr = list(map(int, input().split()))

sums = [0] * (N+1)
sum = 0

for i in range(N) :
    sums[i+1] = sums[i] + arr[i]

max = sums[K] - sums[0]
for i in range(N-K+1):
    diff = sums[i+K] - sums[i]
    max = diff if max < diff else max 

print(max) 