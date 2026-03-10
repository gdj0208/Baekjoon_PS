
def is_exist(num, li, start, end):
    s = start
    e = end

    while s < e :
        m = int((s+e)/2)
        
        if num < li[m] :
            e = m
        elif li[m] < num :
            s = m + 1
        else :
            return True
        
    return li[m] == num

size1 = int(input())
list1 = list(map(int, input().split()))

size2 = int(input())
list2 = list(map(int, input().split()))

list1.sort()

for num in list2:
    if is_exist(num, list1, 0, size1):
        print(1, end = " ")
    else :
        print(0, end = " ")