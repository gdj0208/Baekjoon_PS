
import heapq
import sys

input = sys.stdin.readline

my_heap = []
rpt = int(input())
for _ in range(rpt):
    num = int(input())

    if num == 0 :
        if len(my_heap) == 0:
            print(0)
        else :
            print(-heapq.heappop(my_heap))
    else :
        heapq.heappush(my_heap, -num)