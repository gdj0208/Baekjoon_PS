
import sys

def get_lugs(trees, height) :
    sum = 0
    
    for tree in trees :
        if height < tree:
            sum += tree - height

    return sum

def find_height(list, size, req) :
    start = 0
    end = list[size-1]
    ans = 0

    while(start < end) :
        mid = (start + end) // 2
        
        sum = get_lugs(list, mid)

        if(sum > req) :
            start = mid+1
            ans = mid
        elif(sum < req) :
            end = mid
        else :
            return mid
    return ans

num_tree, req = map(int, input().split())
trees = list(map(int, input().split()))
trees.sort()

print(find_height(trees, num_tree, req))