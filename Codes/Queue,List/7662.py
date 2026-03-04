import heapq
import sys

min_h, max_h = [], []
visited = []

def merge():
    global visited,min_h, max_h

    while min_h and not visited[min_h[0][1]]:
        heapq.heappop(min_h)
    while max_h and not visited[max_h[0][1]]:
        heapq.heappop(max_h)

def del_heapq(op):
    global visited,min_h, max_h

    if op == 1: 
        while max_h and not visited[max_h[0][1]]:
            heapq.heappop(max_h)
        if max_h:
            visited[max_h[0][1]] = False
            heapq.heappop(max_h)
    else: 
        while min_h and not visited[min_h[0][1]]:
            heapq.heappop(min_h)
        if min_h:
            visited[min_h[0][1]] = False
            heapq.heappop(min_h)

def solve(op_num):
    global visited,min_h, max_h
    visited = [False] * op_num
    min_h = []
    max_h = []
        
    for i in range(op_num):
        order, num = input().split()
        n = int(num)
        
        if order == 'I':
            heapq.heappush(min_h, (n, i))
            heapq.heappush(max_h, (-n, i))
            visited[i] = True 
            
        elif order == 'D':
            del_heapq(n)
    
    merge()
        
    if not min_h or not max_h:
        print("EMPTY")
    else:
        print(-max_h[0][0], min_h[0][0])


input = sys.stdin.readline

rpt = int(input())
for _ in range(rpt):
    op_num = int(input())
    solve(op_num)