
size = int(input())
sum = []
arr = []


for i in range(size) :
    arr.append(int(input()))

if size == 1 :
    print(arr[0])
elif size == 2:
    print(arr[0] + arr[1])
else :
    sum.append(arr[0])
    sum.append(arr[0]+arr[1])
    sum.append(max(arr[0]+arr[1], arr[0]+arr[2], arr[1]+arr[2]))
    for i in range(3, size) :
        next = max(sum[i-1], sum[i-2]+arr[i], sum[i-3] + arr[i] + arr[i-1])
        sum.append(next)
    print(sum[-1])
