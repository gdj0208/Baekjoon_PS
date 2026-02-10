import copy

size = int(input())
arr = list(map(int, input().split()))
rpt = int(input())

for _ in range(rpt):
    sex, switch = map(int, input().split())

    if sex == 1 :
        idx = switch-1
        while idx < size :
            arr[idx] = (arr[idx] + 1) % 2
            idx += switch
    else :
        idx = switch - 1
        left = idx - 1
        right = idx + 1
        arr[idx] = (arr[idx] + 1) % 2

        while(0 <= left and right < size) :
            if arr[left] == arr[right]:
                arr[left] = (arr[left] + 1) % 2
                arr[right] = (arr[right] + 1) % 2
                left -= 1
                right += 1
            else :
                break

for i in range(size):
    print(arr[i], end=" ")
    if (i+1) % 20 == 0 :
        print()

