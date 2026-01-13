
import heapq

add = 0

arr = []
size_of_arr = int(input())
for i in range(size_of_arr) :
    arr.append(int(input()))

heapq.heapify(arr)
while(len(arr) != 1) :
    first = heapq.heappop(arr)
    second = heapq.heappop(arr)
    sum = first + second
    add += sum
    heapq.heappush(arr, sum)

print(add)
