
arr1 = []
arr2 = []

size_arr1 = int(input())
arr1 = list(map(int, input().split()))

arr1.sort()

size_arr2 = int(input())
arr2 = list(map(int, input().split()))
for search in arr2 :
    
    found = False
    start = 0
    end = size_arr1

    while start < end :
        mid = (int)((start + end) / 2)

        if search < arr1[mid] :
            end = mid
        elif arr1[mid] < search :
            start = mid + 1 
        else :
            found = True
            break
        
    if found == True:
        print("1")
    else :
        print("0")